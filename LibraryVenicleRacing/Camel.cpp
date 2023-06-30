#include "Camel.h"
#include <iostream>
#include <cmath>
Camel::Camel() : VGround("Верблюд", 10)
{
}
double Camel::time(int dist) const
{
	double x, y, t, x2;
	x = dist / static_cast<double>(speed);
	if (x < timeRest)
		return x;
	else
	{
		t = (x / timeRest);
		t = t - floor(t);
		if (t != 0)
		{
			y = ((x / timeRest) - 1) * 8 + 5;
			x = x + y;
		}
		else
		{
			y = ((x / timeRest) - 2) * 8 + 5;
			x = x + y;
		}
		return x;
	}
}