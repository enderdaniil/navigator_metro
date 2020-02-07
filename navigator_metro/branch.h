#pragma once
#include "station.h"
#include <list>
class branch
{
public:
	std::list<station> list_of_stations;
	void include_station(station station);
};

