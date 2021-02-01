#include "CurrentSensor.h"

constexpr int MA_TO_UA = 1000;
constexpr char NUM_SAMPLES = 10;

CurrentSensor::CurrentSensor(PinName mosi, PinName miso, PinName sclk, PinName cs) : spi_(mosi, miso, sclk), cs_(cs){}

bool CurrentSensor::Get_Current_mA(int* current){
  cs_ = 1; // Select SSI protocol by setting CS high
  ThisThread::sleep_for(1ms);
  int spiBytes = 0;
  for (int i = 0; i < NUM_SAMPLES; i++){
    spiBytes += spi_.write(0xFFFF); // ADC returns 2 bytes
  }
  if (spiBytes == 0){
    cs_ = 0;
    return false; // error communicating with sensor
  } else {
    spiBytes /= NUM_SAMPLES; // taking average
    *current = ((spiBytes * m_slope_uv) - m_offset_uv) / MA_TO_UA; // current in mA
    cs_ = 0;
    return true;
  }
}

bool CurrentSensor::Set_Zero_Point(){
  cs_ = 1; // Select SSI protocol by setting CS high
  int spiBytes = 0;
  for (int i =0; i < NUM_SAMPLES; i++){
    spiBytes += spi_.write(0xFFFF);
  }
  if (spiBytes == 0){
    cs_ = 0;
    return false; // error communicating with sensor
  } else {
    spiBytes /= NUM_SAMPLES; // taking average
    m_offset_uv = spiBytes * MA_TO_UA;
    cs_ = 0;
    return true;
  }
}


