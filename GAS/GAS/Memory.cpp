#include <mutex>
#include <future>
#include "Memory.hpp"



void Memory::SetThreshold(int threshold)
{
	dataThreshold = threshold;
}

void Memory::WriteToFile()
{		
	//std::lock_guard<std::mutex> humidityLock(humidityMutex);
	//std::lock_guard<std::mutex> temperatureLock(temperatureMutex);	

	//auto handle = std::async(std::launch::async, &Details::FileWriter::WriteData<double>, std::string("temperature"), temperature);
	//auto handle1 = std::async(std::launch::async, &Details::FileWriter::WriteData<double>, std::string("humidity"), humidity);

	//fileWriter.WriteData<double>("temperature", temperature);
	//fileWriter.WriteData<int>("humidity", humidity);

	//temperature.data.clear();
	//humidity.data.clear();
}