#pragma once
#include <string>
#include "Vair.h"
class Magiccarpet: public Vair
{
private:
	const std::string name = "����-������";
	const int speed = 10;
public:
	Magiccarpet();
	double time(int* dist) const override;
};

