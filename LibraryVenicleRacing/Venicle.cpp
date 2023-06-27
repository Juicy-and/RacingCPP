#include "Venicle.h"

Venicle::Venicle(std::string veniclename, int speed) : veniclename_(veniclename), speed_(speed)
{
}

std::string Venicle::get_veniclename()
{ 
	return veniclename_; 
}


