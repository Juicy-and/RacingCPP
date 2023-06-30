#pragma once
#include <string>
class Vehicle
{
private:
	std::string vehiclename_;
	int speed_;
public:
	Vehicle(std::string veniclename, int speed);
	std::string get_vehiclename();
	virtual double time(int dist) const = 0;
};

