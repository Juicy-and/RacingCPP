#pragma once
#include "VGround.h"
#include <string>
class Camel : public VGround
{
private:
	const std::string name = "�������";
	const int speed = 10;
	const int timeRest = 30;
public:
	Camel();
	double time(int dist) const override;
};


