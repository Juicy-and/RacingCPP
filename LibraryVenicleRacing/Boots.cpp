
#include "Boots.h"

Boots::Boots() : VGround("Ботинки-вездеходы", 6)
{
}
double Boots::time(int *dist) const
{
	double x, y;
	x = *dist / static_cast<double>(speed);
	if (x < timeRest)
		return x;
	else
	{
		y = ((x / timeRest) - 1) * 5 + 10;
		x = x + y;
		return x;
	}
}


