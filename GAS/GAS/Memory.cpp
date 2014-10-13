#include <mutex>
#include <future>
#include "Memory.hpp"
#include "FileWriter.hpp"

void Memory::SetThreshold(int cachesize)
{
	cacheSize = cachesize;
}

void Memory::WriteTemperatureToFile()
{	
	//std::lock_guard<std::mutex> temperatureLock(temperatureMutex);	

	auto func = std::bind(&Details::FileWriter::WriteData<double>, &fileWriter, std::placeholders::_1, std::placeholders::_2);
	auto handle = std::async(std::launch::async, func, std::string("temperature"), temperature);

	temperature.data.clear();
}


void Memory::WriteHumidityToFile()
{
	//std::lock_guard<std::mutex> humidityLock(humidityMutex);

	auto func = std::bind(&Details::FileWriter::WriteData<int>, &fileWriter, std::placeholders::_1, std::placeholders::_2);
	auto handle = std::async(std::launch::async, func, std::string("humidity"), humidity);

	humidity.data.clear();
}