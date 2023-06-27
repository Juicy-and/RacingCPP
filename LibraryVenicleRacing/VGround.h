#pragma once
#include "Venicle.h"

class VGround : public Venicle
{
private:
	int timeRest_;
public:
	VGround(std::string name, int speed);
	
};

