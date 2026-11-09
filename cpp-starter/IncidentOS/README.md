# IncidentOS C++ backend

This C++17 application loads incident events from JSON, runs starter analysis, and asks an OpenRouter model to write an evidence-grounded incident summary. The model is pretrained and used for inference; this project does not train a model.

## Requirements

On macOS, install CMake and the C++ libraries:

```sh
brew install cmake curl nlohmann-json
```

Create an API key at [OpenRouter](https://openrouter.ai/keys). The default model is `openrouter/free`. Keep the key in your terminal environment; do not put it in source files or screenshots.

## Build and run

Run these commands from `cpp-starter/IncidentOS`:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
```

Set the key in the current zsh terminal without displaying it:

```sh
read -s "OPENROUTER_API_KEY?Paste OpenRouter API key: "; echo; export OPENROUTER_API_KEY
```

Then run the demo:

```sh
./build/incidentos
```

The demo reads `data/sample/events.json`, prints the AI summary, and saves it to `output/incident_summary.md`. You can pass another JSON file as the first argument:

```sh
./build/incidentos path/to/events.json
```

To run the starter checks:

```sh
ctest --test-dir build --output-on-failure
```

Only send sample or non-sensitive telemetry to hosted models. Free-model availability and limits depend on the provider.

## Project layout

- `include/incidentos/models/`: event and finding types
- `include/incidentos/collector/`, `src/collector/`: JSON event loading
- `include/incidentos/analysis/`, `src/analysis/`: anomaly, correlation, timeline, and RCA starters
- `include/incidentos/ai/`, `src/ai/`: OpenRouter incident summarizer
- `include/incidentos/simulation/`, `src/simulation/`: demo incident fixture
- `tests/`: dependency-free starter checks
- `docs/`: architecture and event contract
- `data/sample/`: demo telemetry

## Next backend task

Add a small local HTTP endpoint that accepts an event array, calls the existing summary pipeline, and returns JSON for the React dashboard. Keep the server bound to localhost and keep the OpenRouter key in the C++ process.
