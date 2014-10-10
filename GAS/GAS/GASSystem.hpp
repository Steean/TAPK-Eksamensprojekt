#include <iostream>
#include <memory>
#include "TemperatureSensor.hpp"
#include "HumiditySensor.hpp"
#include "DataObjects.hpp"
#include "Memory.hpp"
#include "WindowWater.hpp"

#ifndef GASSYSTEM_HPP
#define GASSYSTEM_HPP

class GASSystem
{
public:
	GASSystem(TemperatureSensor* tempsens, HumiditySensor* humsens, Settings setting);	
	template <typename T>
	void SaveDataFromSensors(T data);	
private:
	void ProcessTemperature(double temp);
	void ProcessHumidity(int hum);
	TemperatureSensor* _temperatureSensor;
	HumiditySensor* _humiditySensor;
	Settings _settings;
	Machine greenhouse;
	Memory memory;
};
#endif