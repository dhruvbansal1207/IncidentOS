cmake_minimum_required(VERSION 3.16)
project(IncidentOS VERSION 0.1.0 LANGUAGES CXX)
find_package(CURL REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(incidentos_core
  src/collector/collector.cpp
  src/ai/free_model_summarizer.cpp
  src/analysis/anomaly_detector.cpp
  src/analysis/correlation.cpp
  src/analysis/timeline.cpp
  src/analysis/rca.cpp
  src/simulation/simulator.cpp)
target_include_directories(incidentos_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(incidentos_core
    PUBLIC
        CURL::libcurl
        nlohmann_json::nlohmann_json
)
target_compile_options(incidentos_core PRIVATE -Wall -Wextra -Wpedantic)
add_executable(incidentos src/main.cpp)
target_link_libraries(incidentos PRIVATE incidentos_core)
add_executable(incidentos_tests tests/test_main.cpp)
target_link_libraries(incidentos_tests PRIVATE incidentos_core)
enable_testing()
add_test(NAME incidentos_tests COMMAND incidentos_tests)
