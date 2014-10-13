#include "TemperatureSensor.hpp"
TemperatureSensor::TemperatureSensor(IntervalTimer* timer)
{
	_intervalTimer = timer;
	_intervalTimer->timerSignal.connect(boost::bind(&TemperatureSensor::Read, this));
	SimulationMax = 25.0;
	SimulationMin = 0.0;
	SimulationStep = 0.5;
}

void TemperatureSensor::Read()
{
	if (t < SimulationMax && rising)
	{
		t += SimulationStep;
	}
	else if (t > SimulationMin && !rising)
	{
		t -= SimulationStep;
	}	

	if (t >= SimulationMax)
		rising = false;
	if (t <= SimulationMin)
		rising = true;

	temperatureSignal(t);
}