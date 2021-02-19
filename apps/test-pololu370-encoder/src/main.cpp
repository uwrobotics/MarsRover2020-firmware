#include "Pololu37D.h"

int main() {
  constexpr Encoder::Pololu37D::Config config = {PA_10, PB_5, NC, 1, GPIO::QEI::Encoding::X2_ENCODING};
  Encoder::Pololu37D enc(config);

  Timer theta_timer, theta_dot_timer;
  float theta     = 0;
  float theta_dot = 0;
  while (true) {
    theta_timer.reset();
    theta_dot_timer.reset();

    theta_timer.start();
    enc.getAngleDeg(theta);  // returns true if successful
    theta_timer.stop();

    theta_dot_timer.start();
    enc.getAngularVelocityDegPerSec(theta_dot);  // returns true if successful
    theta_dot_timer.stop();

    printf("Angle reading took: %lluus\tAngle: %.3f\r\n", theta_timer.elapsed_time().count(), theta);
    printf("Angular speed reading took: %lluus\tSpeed: %.3f\r\n", theta_dot_timer.elapsed_time().count(), theta_dot);

    ThisThread::sleep_for(500ms);
  }
}