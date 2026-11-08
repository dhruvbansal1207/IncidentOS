#include "incidentos/collector/collector.hpp"
namespace incidentos { void Collector::ingest(Event event) { events_.push_back(std::move(event)); } const std::vector<Event>& Collector::events() const { return events_; } }
