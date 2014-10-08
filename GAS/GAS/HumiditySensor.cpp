#include "HumiditySensor.hpp"

HumiditySensor::HumiditySensor(IntervalTimer* timer)
{
	_intervalTimer = timer;
	_intervalTimer->timerSignal.connect(boost::bind(&HumiditySensor::Read, this));
}

void HumiditySensor::Read()
{
		humiditySignal(30);
}