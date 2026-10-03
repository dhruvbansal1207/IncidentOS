# Ownership

## Person 1: Backend + Observability
Simulated microservices, telemetry SDK, collector, dependency graph, failure simulation and ground truth.
Folders: `services/`, `telemetry_sdk/`, `collector/`, `simulation/`, `tests/p1/`

## Person 2: Intelligence + AI + Frontend
Anomaly detection, correlation, timeline, RCA, LLM integration, investigation API, dashboard.
Folders: `analysis/`, `llm/`, `api/`, `dashboard/`, `tests/p2/`

## Shared
`data/` (schemas are the contract), `evaluation/`, `docs/`, root files.

## Rule
Do not edit a file in the other person's folders without telling them. Changing anything in `data/schemas/` needs both people to agree first.
