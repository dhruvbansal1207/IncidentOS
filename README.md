# IncidentOS

IncidentOS is a student-scale project for investigating production incidents by correlating logs, metrics, traces, deployments, and service dependencies.

## Current starter

The C++17 backend starter is in [`cpp-starter/IncidentOS/`](cpp-starter/IncidentOS/). It builds independently with CMake and Apple Clang and has no third-party C++ dependencies. Follow its README to build and run the executable, run the CTest smoke check, and start the first coding task.

```sh
cd cpp-starter/IncidentOS
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
./build/incidentos
ctest --test-dir build --output-on-failure
```

## Other project assets

- `dashboard/` contains the existing React UI scaffold.
- `data/` contains sample incident telemetry and JSON contracts.
- `docs/` contains architecture and project notes.
- `simulation/` contains scenario fixtures for future C++ simulation work.

The dashboard and legacy data contracts are not yet wired to the C++ executable. The backend starter README describes the current implementation and next task.
