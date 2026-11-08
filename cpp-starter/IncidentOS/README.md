# IncidentOS — C++ starter

A clean, C++17-first starting point for an incident analysis system. It builds with Apple Clang and CMake and has no third-party C++ dependencies. The initial executable runs a small in-memory latency incident through placeholder analysis modules. The JSON file in `data/sample/` documents the event shape; parsing and persistence are intentionally left as coding work.

## Build and run (macOS)

Install Xcode Command Line Tools and CMake if needed:

```sh
xcode-select --install
brew install cmake
```

From the extracted `IncidentOS` directory:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
./build/incidentos
ctest --test-dir build --output-on-failure
```

Expected output includes 4 events, a latency anomaly, cross-service correlation, and a low-confidence RCA suggestion.

## First coding task

Implement a JSON-lines event loader in `src/collector/` using only the C++ standard library (or propose a JSON dependency before adding one). Load `data/sample/events.json`, validate required fields, and pass events through the existing timeline and analysis functions. Add malformed-input cases to `tests/test_main.cpp`.

## Layout

- `include/incidentos/models/`: shared domain types
- `include/incidentos/collector/`, `src/collector/`: ingestion boundary
- `include/incidentos/analysis/`, `src/analysis/`: anomaly, correlation, timeline, RCA starters
- `include/incidentos/simulation/`, `src/simulation/`: deterministic incident fixture
- `tests/`: dependency-free smoke checks, wired into CTest
- `docs/`: architecture and event contract
- `data/sample/`: small illustrative telemetry fixture

The analysis functions are deliberately simple scaffolding, not production incident diagnosis. The project does not include a web API, database, React app, or Python code yet.
