#ifndef HUMIDITYSENSOR_HPP
#define HUMIDITYSENSOR_HPP

#include <boost\signals2.hpp>
#include "IntervalTimer.hpp"

class HumiditySensor
{
private:
	IntervalTimer* _intervalTimer;
	int h = 100;
	bool rising = false;
public:
	HumiditySensor(IntervalTimer* timer);	
	boost::signals2::signal<void(int)> humiditySignal;
	void Read();
};

#endif