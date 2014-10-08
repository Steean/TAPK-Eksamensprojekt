#include <thread>
#include "IntervalTimer.hpp"

void IntervalTimer::Start(std::chrono::milliseconds interval)
{
	running = true;

	th = std::thread([=]()
	{
		while (running)
		{
			std::this_thread::sleep_for(interval);
			timerSignal();
		}
	});
}

void IntervalTimer::Stop()
{
	running = false;
	th.join();
}