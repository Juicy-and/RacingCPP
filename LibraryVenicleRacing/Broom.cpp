#include "Broom.h"
Broom::Broom(): Vair("�����", 20)
{
}
double Broom::time(int dist) const
{
	return (dist - (dist / 100) * (dist / 1000)) / static_cast<double>(speed);
}