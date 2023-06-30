#pragma once
#include "Vehicle.h"

class VGround : public Vehicle
{
private:
	int timeRest_;
public:
	VGround(std::string name, int speed);
	
};

