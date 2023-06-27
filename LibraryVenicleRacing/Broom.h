#pragma once
#include <string>
#include "Vair.h"
class Broom : public Vair
{
private:
	const std::string name = "Метла";
	const int speed = 20;
public:
	Broom();
	double time(int* dist) const override;
};

