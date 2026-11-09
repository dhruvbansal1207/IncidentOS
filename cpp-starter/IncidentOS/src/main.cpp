#include "incidentos/ai/summarizer.hpp"
#include "incidentos/analysis/anomaly_detector.hpp"
#include "incidentos/analysis/correlation.hpp"
#include "incidentos/analysis/rca.hpp"
#include "incidentos/analysis/timeline.hpp"
#include "incidentos/collector/collector.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    const std::string input_path =
        (argc > 1) ? argv[1] : "data/sample/events.json";

    incidentos::Collector collector;
    std::string error;

    if (!collector.load_json_file(input_path, error)) {
        std::cerr << "Could not load events: " << error << '\n';
        return 1;
    }

    const auto events = incidentos::build_timeline(collector.events());
    const auto anomalies = incidentos::detect_anomalies(events);
    const auto correlations = incidentos::correlate_events(events);
    const auto root_cause = incidentos::suggest_root_cause(events);

    std::vector<incidentos::Finding> findings = anomalies;
    findings.insert(findings.end(), correlations.begin(), correlations.end());
    findings.push_back(root_cause);

    std::cout << "IncidentOS | loaded events: " << events.size() << '\n';

    std::string summary;
    if (!incidentos::ai::summarize_incident(
            events, findings, summary, error)) {
        std::cerr << "Could not generate AI summary: " << error << '\n';
        return 1;
    }

    std::cout << "\nAI incident summary:\n" << summary << '\n';

    std::error_code filesystem_error;
    std::filesystem::create_directories("output", filesystem_error);

    if (filesystem_error) {
        std::cerr << "Could not create output folder: "
                  << filesystem_error.message() << '\n';
        return 1;
    }

    std::ofstream report("output/incident_summary.md");
    if (!report) {
        std::cerr << "Could not create output/incident_summary.md\n";
        return 1;
    }

    report << summary << '\n';
    if (!report) {
        std::cerr << "Could not write the incident summary\n";
        return 1;
    }

    std::cout << "\nSaved summary to output/incident_summary.md\n";
    return 0;
}