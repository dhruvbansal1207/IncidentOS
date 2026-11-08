#include "incidentos/analysis/anomaly_detector.hpp"
#include "incidentos/analysis/correlation.hpp"
#include "incidentos/analysis/rca.hpp"
#include "incidentos/analysis/timeline.hpp"
#include "incidentos/simulation/simulator.hpp"
#include <iostream>
int main() { auto events=incidentos::build_timeline(incidentos::simulate_latency_spike()); std::cout << "IncidentOS starter | events: " << events.size() << "\n"; for(const auto& f:incidentos::detect_anomalies(events)) std::cout << "[anomaly] " << f.service << ": " << f.summary << "\n"; for(const auto& f:incidentos::correlate_events(events)) std::cout << "[correlation] " << f.summary << "\n"; const auto r=incidentos::suggest_root_cause(events); std::cout << "[RCA] " << r.summary << " (confidence " << r.confidence << ")\n"; return 0; }
