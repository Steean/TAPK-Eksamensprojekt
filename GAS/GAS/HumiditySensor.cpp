#include "HumiditySensor.hpp"

HumiditySensor::HumiditySensor(IntervalTimer* timer)
{
	_intervalTimer = timer;
	_intervalTimer->timerSignal.connect(boost::bind(&HumiditySensor::Read, this));
}

void HumiditySensor::Read()
{
	if (h < 100 && rising)
	{
		h++;
	}
	else if (h > 0 && !rising)
	{
		h--;
	}

	if (h == 100)
		rising = false;
	if (h == 0)
		rising = true;

	humiditySignal(h);
}