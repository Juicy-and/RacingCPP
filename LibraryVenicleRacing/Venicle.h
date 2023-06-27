#pragma once
#include <string>
class Venicle
{
private:
	std::string veniclename_;
	int speed_;
public:
	Venicle(std::string veniclename, int speed);
	std::string get_veniclename();
	virtual double time(int* dist) const = 0;
};

