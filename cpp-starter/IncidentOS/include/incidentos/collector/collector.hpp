#pragma once
#include "incidentos/models/event.hpp"
#include <vector>
namespace incidentos { class Collector { public: void ingest(Event event); const std::vector<Event>& events() const; private: std::vector<Event> events_; }; }
