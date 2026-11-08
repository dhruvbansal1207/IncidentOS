#pragma once
#include <string>
#include <vector>

namespace incidentos {
enum class EventKind { Metric, Log, Trace, Deployment };
struct Event {
  std::string id;
  std::string timestamp; // ISO-8601 UTC, lexicographically sortable
  std::string service;
  EventKind kind{EventKind::Metric};
  std::string name;
  double value{0.0};
  std::string message;
};
struct Incident { std::string id; std::string title; std::vector<Event> events; };
struct Finding { std::string category; std::string summary; std::string service; double confidence{0.0}; };
}
