#include "Speedcamel.h"

Speedcamel::Speedcamel() : VGround("Верблюд-быстроход", 40)
{
}
double Speedcamel::time(int* dist) const
{
	double x, y;
	x = *dist / static_cast<double>(speed);
	if (x < timeRest)
		return x;
	else
	{
		y = ((x / timeRest) - 2) * 8 + 5 + 6.5;
		x = x + y;
		return x;
	}
}