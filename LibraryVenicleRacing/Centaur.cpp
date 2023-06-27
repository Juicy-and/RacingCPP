#include "Centaur.h"

Centaur::Centaur() : VGround("Кентавр", 15)
{
}
double Centaur::time(int* dist) const
{
	double x, y;
	x = *dist / static_cast<double>(speed);
	if (x < timeRest)
		return x;
	else
	{
		y = (x / timeRest) * 2;
		x = x + y;
		return x;
	}
}
