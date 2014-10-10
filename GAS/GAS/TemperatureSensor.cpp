#include "TemperatureSensor.hpp"
TemperatureSensor::TemperatureSensor(IntervalTimer* timer)
{
	_intervalTimer = timer;
	_intervalTimer->timerSignal.connect(boost::bind(&TemperatureSensor::Read, this));
}

void TemperatureSensor::Read()
{
	if (t < 25.0 && rising)
	{
		t += 0.5;
	}
	else if (t > 0.0 && !rising)
	{
		t -= 0.5;
	}	

	if (t >= 25.0)
		rising = false;
	if (t <= 0.0)
		rising = true;

	temperatureSignal(t);
}