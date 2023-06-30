#pragma once
#include <string>
#include "Vair.h"
class MagicCarpet: public Vair
{
private:
	const std::string name = "Ковёр-самолёт";
	const int speed = 10;
public:
	MagicCarpet();
	double time(int dist) const override;
};

