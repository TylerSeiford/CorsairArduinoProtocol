#include "IFan.h"
#include "CLPUtils.h"

uint8_t IFan::calculatePowerFromSpeed(uint16_t rpm)
{
	rpm = constrain(rpm, minRPM, maxRPM);
	return ((float)(rpm - minRPM) / (float)(maxRPM - minRPM)) * 255;
}

uint16_t IFan::calculateSpeedFromPower(uint8_t power)
{
	return map(power, 0, 255, minRPM, maxRPM);
}