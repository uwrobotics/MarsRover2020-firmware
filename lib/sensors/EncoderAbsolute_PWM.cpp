
#include "EncoderAbsolute_PWM.h"

EncoderAbsolute_PWM::EncoderAbsolute_PWM(t_encoderConfig encoderConfig) :
		Encoder(encoderConfig), m_pwmIn(encoderConfig.pin_PWM), 
		m_degreesPerUnit(encoderConfig.degreesPerUnit), m_zeroOffset_Degrees(encoderConfig.offset_Degrees) {}

EncoderAbsolute_PWM::~EncoderAbsolute_PWM() {}

Encoder::t_encoderType EncoderAbsolute_PWM::getType() {
	return encoderType::absolute;
}

float EncoderAbsolute_PWM::getAngle_Degrees() {
	return (m_pwmIn.avgDutyCycle() * m_degreesPerUnit) - m_zeroOffset_Degrees;
}

float EncoderAbsolute_PWM::getVelocity_DegreesPerSec() {
	return m_pwmIn.avgDutyCycleVelocity() * m_degreesPerUnit;
}