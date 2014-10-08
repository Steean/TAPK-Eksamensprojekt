#include <iostream>
#include "TemperatureSensor.hpp"
#include "HumiditySensor.hpp"
#include "DataObjects.hpp"

#ifndef GASSYSTEM_HPP
#define GASSYSTEM_HPP

class GASSystem
{
public:
	GASSystem(TemperatureSensor* tempsens, HumiditySensor* humsens);
	template <typename T>
	void PutData(T data)
	{
		std::cout << data;
		
	}
private:
	TemperatureSensor* _temperatureSensor;
	HumiditySensor* _humiditySensor;
	Settings _settings;
};
#endif