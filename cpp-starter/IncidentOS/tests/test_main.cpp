#include "incidentos/analysis/anomaly_detector.hpp"
#include "incidentos/analysis/timeline.hpp"
#include "incidentos/collector/collector.hpp"
#include "incidentos/simulation/simulator.hpp"
#include <cassert>
#include <iostream>
int main(){ auto events=incidentos::simulate_latency_spike(); assert(events.size()==4); auto sorted=incidentos::build_timeline(events); assert(sorted.front().timestamp<=sorted.back().timestamp); auto findings=incidentos::detect_anomalies(events); assert(findings.size()==1); incidentos::Collector c; c.ingest(events.front()); assert(c.events().size()==1); std::cout<<"Starter checks passed\n"; }
