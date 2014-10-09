#include <typeinfo>
#include "GASSystem.hpp"
#include "WindowWater.hpp"

GASSystem::GASSystem(TemperatureSensor* tempsens, HumiditySensor* humsens, int threshold)
{
	_temperatureSensor = tempsens;
	_humiditySensor = humsens;
	_temperatureSensor->temperatureSignal.connect(boost::bind(&GASSystem::SaveDataFromSensors<double>, this, _1));
	_humiditySensor->humiditySignal.connect(boost::bind(&GASSystem::SaveDataFromSensors<int>, this, _1));

	memory.SetThreshold(threshold);

	greenhouse.initiate();
}

template <typename T>
void GASSystem::SaveDataFromSensors(T data)
{
	if (typeid(T) == typeid(double))
	{
		ProcessTemperature(data);
	}
	else if (typeid(T) == typeid(int))
	{
		ProcessHumidity(data);
	}

	memory.PutData(data);
}

void GASSystem::ProcessTemperature(double temp)
{
	if (temp > _settings.maxTemperature)
	{
		greenhouse.process_event(MaxTemperatureThreshold());
	}
	else if (temp < _settings.minTemperature)
	{
		greenhouse.process_event(MinTemperatureThreshold());
	}
}

void GASSystem::ProcessHumidity(int hum)
{
	if (hum > _settings.maxHumidity)
	{
		greenhouse.process_event(MaxHumidityThreshold());
	}
	else if (hum < _settings.minHumidity)
	{
		greenhouse.process_event(MinHumidityThreshold());
	}
}

