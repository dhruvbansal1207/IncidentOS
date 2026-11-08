cmake_minimum_required(VERSION 3.16)
project(IncidentOS VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(incidentos_core
  src/collector/collector.cpp
  src/analysis/anomaly_detector.cpp
  src/analysis/correlation.cpp
  src/analysis/timeline.cpp
  src/analysis/rca.cpp
  src/simulation/simulator.cpp)
target_include_directories(incidentos_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(incidentos_core PRIVATE -Wall -Wextra -Wpedantic)
add_executable(incidentos src/main.cpp)
target_link_libraries(incidentos PRIVATE incidentos_core)
add_executable(incidentos_tests tests/test_main.cpp)
target_link_libraries(incidentos_tests PRIVATE incidentos_core)
enable_testing()
add_test(NAME incidentos_tests COMMAND incidentos_tests)
