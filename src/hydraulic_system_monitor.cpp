#include "robot_info/hydraulic_system_monitor.h"
#include <string>
#include <tuple>

using namespace std;

HydraulicSystemMonitor::HydraulicSystemMonitor(
    string hydraulic_oil_temperature, string hydraulic_oil_tank_fill_level,
    string hydraulic_oil_pressure) {
  this->hydraulic_oil_temperature = hydraulic_oil_temperature;
  this->hydraulic_oil_tank_fill_level = hydraulic_oil_tank_fill_level;
  this->hydraulic_oil_pressure = hydraulic_oil_pressure;
}

string HydraulicSystemMonitor::get_hydraulic_oil_temperature() {
  return hydraulic_oil_temperature;
}

string HydraulicSystemMonitor::get_hydraulic_oil_tank_fill_level() {
  return hydraulic_oil_tank_fill_level;
}

string HydraulicSystemMonitor::get_hydraulic_oil_pressure() {
  return hydraulic_oil_pressure;
}

tuple<string, string, string> HydraulicSystemMonitor::system_monitor_info() {
  return {hydraulic_oil_temperature, hydraulic_oil_tank_fill_level,
          hydraulic_oil_pressure};
}

void HydraulicSystemMonitor::set_hydraulic_oil_temperature(string temp) {
  hydraulic_oil_temperature = temp;
}

void HydraulicSystemMonitor::set_hydraulic_oil_tank_fill_level(
    string tank_fill_level) {
  hydraulic_oil_tank_fill_level = tank_fill_level;
}

void HydraulicSystemMonitor::set_hydraulic_oil_pressure(string pressure) {
  hydraulic_oil_pressure = pressure;
}