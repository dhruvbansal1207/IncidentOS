#pragma once
#include "incidentos/models/event.hpp"
#include <vector>
namespace incidentos { std::vector<Finding> correlate_events(const std::vector<Event>& events); }
