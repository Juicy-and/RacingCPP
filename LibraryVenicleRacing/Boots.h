#pragma once
#include "VGround.h"
#include <string>
class Boots : public VGround
{
private:
	std::string name;
	const int speed = 6;
	const int timeRest = 60;
public:
	Boots();
	double time(int dist) const override;
};

