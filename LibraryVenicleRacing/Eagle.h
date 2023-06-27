#pragma once
#include <string>
#include "Vair.h"
class Eagle: public Vair
{
private:
	const std::string name = "Îð¸ë";
	const int speed = 8;
public:
	Eagle();
	double time(int* dist) const override;
};