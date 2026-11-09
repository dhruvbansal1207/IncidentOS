#pragma once

#include "incidentos/models/event.hpp"

#include <string>
#include <vector>

namespace incidentos::ai {

bool summarize_incident(
    const std::vector<Event>& events,
    const std::vector<Finding>& findings,
    std::string& summary,
    std::string& error
);

} // namespace incidentos::ai