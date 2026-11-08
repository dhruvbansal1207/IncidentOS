#pragma once
#include "incidentos/models/event.hpp"
#include <vector>
namespace incidentos { std::vector<Finding> detect_anomalies(const std::vector<Event>& events, double threshold=100.0); }
