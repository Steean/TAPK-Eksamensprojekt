#include <boost\signals2.hpp>
#include "IntervalTimer.hpp"
#ifndef HUMIDITYSENSOR_HPP
#define HUMIDITYSENSOR_HPP

class HumiditySensor
{
private:
	IntervalTimer* _intervalTimer;
public:
	HumiditySensor(IntervalTimer* timer);
	boost::signals2::signal<void(int)> humiditySignal;
	void Read();
};

#endif