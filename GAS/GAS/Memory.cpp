#include <mutex>
#include "Memory.hpp"

Memory::Memory(int threshold)
{
	dataThreshold = threshold;
}

void Memory::WriteToFile()
{		
	//std::lock_guard<std::mutex> humidityLock(humidityMutex);
	//std::lock_guard<std::mutex> temperatureLock(temperatureMutex);
	
	fileWriter.WriteData<double>("temperature", temperature);
	fileWriter.WriteData<int>("humidity", humidity);

	temperature.data.clear();
	humidity.data.clear();

	// writerMutex is automatically released when going out of scope
}