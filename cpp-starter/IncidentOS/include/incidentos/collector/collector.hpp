#pragma once

#include "incidentos/models/event.hpp"

#include <string>
#include <vector>

namespace incidentos {

class Collector {
public:
    void ingest(Event event);
    const std::vector<Event>& events() const;

    // Loads events from a JSON file.
    // Returns false and fills error if the file cannot be read or parsed.
    bool load_json_file(const std::string& path, std::string& error);

private:
    std::vector<Event> events_;
};

} // namespace incidentos