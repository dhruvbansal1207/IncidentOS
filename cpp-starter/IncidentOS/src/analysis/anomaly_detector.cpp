#include "incidentos/analysis/anomaly_detector.hpp"
namespace incidentos { std::vector<Finding> detect_anomalies(const std::vector<Event>& events, double threshold) { std::vector<Finding> out; for (const auto& e: events) if (e.kind==EventKind::Metric && e.value>=threshold) out.push_back({"anomaly", e.name+" exceeded threshold ("+std::to_string(e.value)+")", e.service, 0.75}); return out; } }
