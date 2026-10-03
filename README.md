# IncidentOS

AI-assisted production incident investigation for microservice applications.

IncidentOS correlates logs, metrics, traces, deployments and service dependencies to reconstruct what happened during an incident and produce an evidence-backed probable root cause.

Think of it as Copilot for production incidents. Platforms such as Datadog and Dynatrace solve this at enterprise scale; this is a student-scale end-to-end implementation built to understand how observability, correlation, anomaly detection and AI-assisted RCA work.

## Pipeline

```
Microservices -> Telemetry (logs, metrics, traces) -> Collector
  -> Anomaly detection -> Correlation -> Dependency analysis -> Timeline
  -> Hypotheses -> Verification against evidence -> LLM explanation -> Dashboard
```

The LLM is the last step. It explains verified evidence; it does not guess the root cause.

## Repo layout

| Folder | Owner | What it holds |
|---|---|---|
| `services/` | Person 1 | Simulated order, payment, user services and database |
| `telemetry_sdk/` | Person 1 | Shared logging, metrics and tracing library |
| `collector/` | Person 1 | Ingestion, storage and query API |
| `simulation/` | Person 1 | Load generator, failure injection, scenarios, ground truth |
| `analysis/` | Person 2 | Anomaly detection, correlation, timeline, RCA |
| `llm/` | Person 2 | LLM client, prompts, explainer |
| `api/` | Person 2 | Investigation API for the dashboard |
| `dashboard/` | Person 2 | Frontend |
| `data/` | Both | JSON schemas (the contract) and mock incident data |
| `evaluation/` | Both | Accuracy and ablation experiments |
| `docs/` | Both | Architecture, contracts, viva prep |

See `docs/ownership.md` and `CONTRIBUTING.md`.

## Quick start

```bash
python -m venv .venv
# Windows: .venv\Scripts\activate     macOS/Linux: source .venv/bin/activate
pip install -r requirements.txt
```

Person 2 can start immediately using the mock data in `data/mock/incident_01/`.
