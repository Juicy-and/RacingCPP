#include "Centaur.h"
#include <cmath>

Centaur::Centaur() : VGround("Кентавр", 15)
{
}
double Centaur::time(int dist) const
{
	double x, y,t;
	x = dist / static_cast<double>(speed);
	if (x < timeRest)
		return x;
	else
	{
		t = x / timeRest;
		t = floor(t);
		y = (t) * 2;
		x = x + y;
		return x;
	}
}
