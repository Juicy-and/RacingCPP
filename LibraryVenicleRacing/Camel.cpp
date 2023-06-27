#include "Camel.h"
#include <iostream>
Camel::Camel() : VGround("Верблюд", 10)
{
}
double Camel::time(int* dist) const
{
	double x, y;
	x = *dist / static_cast<double>(speed);
	if (x < timeRest)
		return x;
	else
	{
		y = ((x / timeRest) - 1) * 8 + 5;
		x = x + y;
		return x;
	}
}