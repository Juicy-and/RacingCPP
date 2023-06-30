#include "MagicCarpet.h"

MagicCarpet::MagicCarpet() : Vair("Êîâ¸ğ-ñàìîë¸ò", 10)
{
}
double MagicCarpet::time(int dist) const
{
	double x = dist;
	if (x > 1000 && x < 5000)
		return x * 0.97/ speed;
	else if (x > 5000 && x < 10000)
		return x * 0.9 / speed;
	else if (x >= 10000)
		return x * 0.95 / speed;
	else return x / speed;
}