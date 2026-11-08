#include "incidentos/analysis/correlation.hpp"
#include <set>
namespace incidentos { std::vector<Finding> correlate_events(const std::vector<Event>& events) { std::set<std::string> services; for (const auto& e: events) if(e.kind==EventKind::Log || e.kind==EventKind::Metric) services.insert(e.service); if(services.size()<2) return {}; return {{"correlation", "Signals observed across "+std::to_string(services.size())+" services", "", 0.5}}; } }
