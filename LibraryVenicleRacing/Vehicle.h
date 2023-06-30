#pragma once
#include <string>
class Vehicle
{
private:
	std::string vehicle_name_;
	int speed_;
public:
	Vehicle(std::string venicle_name, int speed);
	std::string get_vehicle_name();
	virtual double time(int dist) const = 0;
};

