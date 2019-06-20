#pragma once

#include "Arduino.h"

class IFan {
public:
	IFan(uint16_t minRPM, uint16_t maxRPM) : minRPM(minRPM), maxRPM(maxRPM) {}
	virtual void setPower(uint8_t percentage);
	uint8_t calculatePowerFromSpeed(uint16_t rpm);
	uint16_t calculateSpeedFromPower(uint8_t power);
protected:
	const uint16_t minRPM;
	const uint16_t maxRPM;
};