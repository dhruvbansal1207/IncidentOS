#include "incidentos/analysis/timeline.hpp"
#include <algorithm>
namespace incidentos { std::vector<Event> build_timeline(std::vector<Event> events) { std::stable_sort(events.begin(), events.end(), [](const Event& a,const Event& b){return a.timestamp<b.timestamp;}); return events; } }
