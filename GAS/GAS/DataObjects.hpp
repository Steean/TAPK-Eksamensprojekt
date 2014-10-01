#include <vector>

#ifndef DATAOBJECTS_HPP
#define DATAOBJECTS_HPP

template <typename T>
struct Data
{
	std::vector<T> data;
};

struct Settings
{
	double maxTemperature;
	double minTemperature;
	int maxHumidity;
	int minHumidity;
	int interval;

	Settings(double maxTemp = 0.0, double minTemp = 0.0, int maxHum = 0, int minHum = 0, int i = 0)
		: maxTemperature(maxTemp), minTemperature(minTemp), maxHumidity(maxHum), minHumidity(minHum), interval(i) {}
};

#endif