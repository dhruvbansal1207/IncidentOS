# Data contract

The authoritative definitions are the JSON schemas in `data/schemas/`.

| Type | Key fields |
|---|---|
| Log | ts, service, level, message, trace_id (optional) |
| Metric | ts, service, name, value |
| Span | trace_id, span_id, parent_span_id, service, operation, start_ts, duration_ms, status |
| Deployment | ts, service, version |
| Dependency graph | service -> list of services it calls |

All timestamps are ISO 8601 in UTC.

Mock example: `data/mock/incident_01/` (payment deployment at 10:30 causes DB timeouts and order failures; the user service is unaffected).

Rule: change a schema only after telling the other person.
