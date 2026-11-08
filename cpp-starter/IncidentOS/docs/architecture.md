# Architecture

The starter is a single C++17 executable backed by a small `incidentos_core` library. Domain structs live under `models`; collector code owns the in-memory ingestion boundary; analysis modules accept event collections and return findings; simulation provides deterministic input. These seams are intended to remain independently replaceable as real inputs and algorithms are added.

No network server, database, async runtime, or third-party library is introduced. Keep I/O at the edges and pass typed domain data into analysis code.
