#include <boost\signals2.hpp>
#include <thread>
#include <chrono>

#ifndef INTERVALTIMER_HPP
#define INTERVALTIMER_HPP

class IntervalTimer
{
public:	
	boost::signals2::signal<void()> timerSignal;
	void Start(std::chrono::milliseconds interval);
	void Stop();
private:
	std::thread th;
	bool running = false;
};

#endif