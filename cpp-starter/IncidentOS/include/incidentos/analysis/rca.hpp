#pragma once
#include "incidentos/models/event.hpp"
#include <vector>
namespace incidentos { Finding suggest_root_cause(const std::vector<Event>& events); }
