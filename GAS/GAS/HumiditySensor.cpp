#include "HumiditySensor.hpp"

HumiditySensor::HumiditySensor(IntervalTimer* timer)
{
	_intervalTimer = timer;
	_intervalTimer->timerSignal.connect(boost::bind(&HumiditySensor::Read, this));
	SimulationMax = 100;
	SimulationMin = 0;
	SimulationStep = 1;
}

void HumiditySensor::Read()
{
	if (h < SimulationMax && rising)
	{
		h += SimulationStep;
	}
	else if (h > SimulationMin && !rising)
	{
		h -= SimulationStep;
	}

	if (h == SimulationMax)
		rising = false;
	if (h == SimulationMin)
		rising = true;

	humiditySignal(h);
}