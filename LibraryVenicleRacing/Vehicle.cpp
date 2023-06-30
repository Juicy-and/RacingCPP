#include "Vehicle.h"

Vehicle::Vehicle(std::string vehicle_name, int speed) : vehicle_name_(vehicle_name), speed_(speed)
{
}

std::string Vehicle::get_vehicle_name()
{ 
	return vehicle_name_; 
}


