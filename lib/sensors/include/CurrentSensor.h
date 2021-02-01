#pragma once

#include "mbed.h"

class CurrentSensor {
 public:
  CurrentSensor(PinName mosi, PinName miso, PinName sclk, PinName cs);
  ~CurrentSensor() = default;


  bool Get_Current_mA(int* current); // gets measured current in mA
  bool Set_Zero_Point(); // sets currently measured amps as 0 current

 private:
  SPI spi_;
  DigitalOut cs_;
  const int m_slope_uv = 35470; // determined from linear regression of characterization results
  int m_offset_uv = 75230800; // non const to allow setting 0 point
};