#include <boost/signals2.hpp>
#include "IntervalTimer.hpp"

#ifndef TEMPERATURESENSOR_HPP
#define TEMPERATURESENSOR_HPP

class TemperatureSensor
{
private:
	IntervalTimer* _intervalTimer;
	double t = 0.0;
	bool rising = true;
public:
	TemperatureSensor(IntervalTimer* timer);	
	boost::signals2::signal<void(double)> temperatureSignal;
	void Read();
};

#endif