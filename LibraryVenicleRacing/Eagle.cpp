
#include "Eagle.h"

Eagle::Eagle() : Vair("���", 8)
{
}

double Eagle::time(int* dist) const
{
	return *dist * 0.94 / speed;
}
