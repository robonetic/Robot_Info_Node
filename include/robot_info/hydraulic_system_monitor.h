#pragma once

#include <string>
#include <tuple>

using namespace std;

class HydraulicSystemMonitor {
public:
  HydraulicSystemMonitor(string hydraulic_oil_temperature,
                         string hydraulic_oil_tank_fill_level,
                         string hydraulic_oil_pressure);
  // GETTERS
  string get_hydraulic_oil_temperature();
  string get_hydraulic_oil_tank_fill_level();
  string get_hydraulic_oil_pressure();

  // SETTERS
  void set_hydraulic_oil_temperature(string temp);
  void set_hydraulic_oil_tank_fill_level(string tank_fill_level);
  void set_hydraulic_oil_pressure(string pressure);

  tuple<string, string, string> system_monitor_info();

protected:
  string hydraulic_oil_temperature;
  string hydraulic_oil_tank_fill_level;
  string hydraulic_oil_pressure;
};