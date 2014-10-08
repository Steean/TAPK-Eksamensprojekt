#include "GASSystem.hpp"

GASSystem::GASSystem(TemperatureSensor* tempsens, HumiditySensor* humsens)
{
	_temperatureSensor = tempsens;
	_humiditySensor = humsens;
	_temperatureSensor->temperatureSignal.connect(boost::bind(&GASSystem::PutData<double>, this, _1));
	_humiditySensor->humiditySignal.connect(boost::bind(&GASSystem::PutData<int>, this, _1));
}