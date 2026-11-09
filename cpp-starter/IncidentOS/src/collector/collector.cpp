#include "incidentos/collector/collector.hpp"

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iterator>
#include <utility>
#include <vector>

namespace incidentos {
namespace {

class Parser {
public:
    explicit Parser(const std::string& text) : text_(text) {}

    bool parse_events(std::vector<Event>& result, std::string& error) {
        skip_space();
        if (!consume('[')) return fail(error, "Expected '['");

        skip_space();
        if (consume(']')) return at_end();

        while (true) {
            Event event;
            if (!parse_event(event, error)) return false;
            result.push_back(std::move(event));

            skip_space();
            if (consume(']')) return at_end();
            if (!consume(',')) return fail(error, "Expected ',' or ']' after event");
        }
    }

private:
    bool parse_event(Event& event, std::string& error) {
        skip_space();
        if (!consume('{')) return fail(error, "Expected an event object");

        bool has_id = false;
        bool has_timestamp = false;
        bool has_service = false;
        bool has_kind = false;
        bool has_name = false;

        while (true) {
            skip_space();
            if (consume('}')) break;

            std::string key;
            if (!parse_string(key, error)) return false;

            skip_space();
            if (!consume(':')) return fail(error, "Expected ':' after field name");
            skip_space();

            if (key == "value") {
                if (!parse_number(event.value, error)) return false;
            } else {
                std::string value;
                if (!parse_string(value, error)) return false;

                if (key == "id") {
                    event.id = value;
                    has_id = true;
                } else if (key == "timestamp") {
                    event.timestamp = value;
                    has_timestamp = true;
                } else if (key == "service") {
                    event.service = value;
                    has_service = true;
                } else if (key == "name") {
                    event.name = value;
                    has_name = true;
                } else if (key == "message") {
                    event.message = value;
                } else if (key == "kind") {
                    has_kind = true;
                    if (value == "metric") event.kind = EventKind::Metric;
                    else if (value == "log") event.kind = EventKind::Log;
                    else if (value == "trace") event.kind = EventKind::Trace;
                    else if (value == "deployment") event.kind = EventKind::Deployment;
                    else return fail(error, "Unknown event kind: " + value);
                }
            }

            skip_space();
            if (consume('}')) break;
            if (!consume(',')) return fail(error, "Expected ',' or '}' after field");
        }

        if (!has_id || !has_timestamp || !has_service || !has_kind || !has_name) {
            return fail(error, "Event is missing a required field");
        }
        return true;
    }

    bool parse_string(std::string& result, std::string& error) {
        skip_space();
        if (!consume('"')) return fail(error, "Expected a quoted string");

        while (position_ < text_.size()) {
            char ch = text_[position_++];
            if (ch == '"') return true;

            if (ch == '\\') {
                if (position_ >= text_.size()) return fail(error, "Incomplete escape");
                char escaped = text_[position_++];
                switch (escaped) {
                    case '"': result += '"'; break;
                    case '\\': result += '\\'; break;
                    case '/': result += '/'; break;
                    case 'n': result += '\n'; break;
                    case 'r': result += '\r'; break;
                    case 't': result += '\t'; break;
                    default: return fail(error, "Unsupported string escape");
                }
            } else {
                result += ch;
            }
        }
        return fail(error, "Unterminated string");
    }

    bool parse_number(double& result, std::string& error) {
        const char* start = text_.c_str() + position_;
        char* end = nullptr;
        result = std::strtod(start, &end);
        if (end == start) return fail(error, "Expected a number");
        position_ += static_cast<std::size_t>(end - start);
        return true;
    }

    bool at_end() {
        skip_space();
        return position_ == text_.size();
    }

    void skip_space() {
        while (position_ < text_.size() &&
               std::isspace(static_cast<unsigned char>(text_[position_]))) {
            ++position_;
        }
    }

    bool consume(char expected) {
        skip_space();
        if (position_ >= text_.size() || text_[position_] != expected) return false;
        ++position_;
        return true;
    }

    bool fail(std::string& error, const std::string& message) {
        error = message + " near character " + std::to_string(position_);
        return false;
    }

    const std::string& text_;
    std::size_t position_{0};
};

} // namespace

void Collector::ingest(Event event) {
    events_.push_back(std::move(event));
}

const std::vector<Event>& Collector::events() const {
    return events_;
}

bool Collector::load_json_file(const std::string& path, std::string& error) {
    std::ifstream file(path);
    if (!file) {
        error = "Could not open file: " + path;
        return false;
    }

    const std::string contents(
        (std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>());

    std::vector<Event> loaded;
    Parser parser(contents);
    if (!parser.parse_events(loaded, error)) return false;

    events_ = std::move(loaded);
    error.clear();
    return true;
}

} // namespace incidentos