#pragma once
#include "VGround.h"
#include <string>
class SpeedCamel : public VGround
{
private:
	const std::string name = "Верблюд-быстроход";
	const int speed = 40;
	const int timeRest = 10;
public:
	SpeedCamel();
	double time(int dist) const override;
};