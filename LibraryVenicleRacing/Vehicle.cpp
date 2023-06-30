#include "Vehicle.h"

Vehicle::Vehicle(std::string vehiclename, int speed) : vehiclename_(vehiclename), speed_(speed)
{
}

std::string Vehicle::get_vehiclename()
{ 
	return vehiclename_; 
}


