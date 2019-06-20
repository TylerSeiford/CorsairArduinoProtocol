#pragma once

#include "Arduino.h"
#include "FanController.h"

class IFan {
public:
	IFan(uint16_t minRPM, uint16_t maxRPM, uint8_t type) : minRPM(minRPM), maxRPM(maxRPM), type(type) {}
	IFan(uint16_t minRPM, uint16_t maxRPM) : minRPM(minRPM), maxRPM(maxRPM), type(FAN_MASK_DISCONNECTED) {}
	virtual void setPower(uint8_t percentage);
	uint8_t calculatePowerFromSpeed(uint16_t rpm);
	uint16_t calculateSpeedFromPower(uint8_t power);
	const uint8_t getType() {
		return type;
	}

protected:
	const uint16_t minRPM;
	const uint16_t maxRPM;
	const uint8_t type;
};