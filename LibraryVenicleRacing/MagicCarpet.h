#pragma once
#include <string>
#include "Vair.h"
class MagicCarpet: public Vair
{
private:
	const std::string name = "����-������";
	const int speed = 10;
public:
	MagicCarpet();
	double time(int dist) const override;
};

