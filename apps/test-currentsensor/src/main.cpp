#include "CurrentSensor.h"

int main(){
  CurrentSensor sensor(SPI_MOSI, SPI_MISO, SPI_SCK, SPI_CS);
  int current_ma = 0;
  constexpr auto SENSOR_DELAY = 2000ms;

  printf("Starting CurrentSensor Test\n");

  while(true){
    sensor.Get_Current_mA(&current_ma);
    printf("Setting 0 Value at %d mA\n", current_ma);
    sensor.Set_Zero_Point();
    ThisThread::sleep_for(SENSOR_DELAY);

    for(int i = 0; i < 10; i++) {
      sensor.Get_Current_mA(&current_ma);
      printf("Measured Current (mA): %d\n", current_ma);
      ThisThread::sleep_for(SENSOR_DELAY);
    }
  }
}
