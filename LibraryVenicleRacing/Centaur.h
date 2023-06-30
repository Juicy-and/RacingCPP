#pragma once
#include "VGround.h"
#include <string>
class Centaur : public VGround
{
private:
	const std::string name = "Кентавр";
	const int speed = 15;
	const int timeRest = 8;
public:
	Centaur();
	double time(int dist) const override;
};