#include <cmath>
#include "Boots.h"

Boots::Boots() : VGround("Ботинки-вездеходы", 6)
{
}
double Boots::time(int dist) const
{
	double x, y, t;
	x = dist / static_cast<double>(speed);
	t = x / timeRest;
	t = floor(t);
	if (x < timeRest)
		return x;
	else
	{
		y = ((t) - 1) * 5 + 10;
		x = x + y;
		return x;
	}
}


