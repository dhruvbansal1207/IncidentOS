# Collector API (Person 1 provides, Person 2 consumes)

Proposed. Adjust together.

- `GET /logs?from=<ts>&to=<ts>&service=<name>`
- `GET /metrics?from=<ts>&to=<ts>&service=<name>&name=<metric>`
- `GET /traces?from=<ts>&to=<ts>&trace_id=<id>`
- `GET /deployments?from=<ts>&to=<ts>`
- `GET /dependencies`

Ingestion (used by the telemetry SDK): `POST /logs`, `POST /metrics`, `POST /traces`, `POST /deployments`.

Until the collector exists, Person 2 reads the same shapes from `data/mock/`.
