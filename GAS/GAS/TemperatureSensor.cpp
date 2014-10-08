#include "TemperatureSensor.hpp"
TemperatureSensor::TemperatureSensor(IntervalTimer* timer)
{
	_intervalTimer = timer;
	_intervalTimer->timerSignal.connect(boost::bind(&TemperatureSensor::Read, this));
}

void TemperatureSensor::Read()
{
	temperatureSignal(22.2);
}