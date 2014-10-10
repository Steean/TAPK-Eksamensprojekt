#include <mutex>
#include <future>
#include <vector>
#include "DataObjects.hpp"
#include "FileWriter.hpp"
#include "FileReader.hpp"

#ifndef MEMORY_HPP
#define MEMORY_HPP

class Memory
{
private:
	Data<double> temperature;
	Data<int> humidity;
	int cacheSize;
	Details::FileWriter fileWriter;
	Details::FileReader fileReader;
	void ThresholdCheck();
	void WriteTemperatureToFile();
	void WriteHumidityToFile();
	//std::mutex temperatureMutex;
	//std::mutex humidityMutex;
public:
	void SetThreshold(int threshold);

	template<typename T, typename std::enable_if<std::is_same<T, int>::value, int>::type = 0>
	Data<T> GetData(int noReadings)
	{
		Data<T> result;
		if (temperature.data.size() >= noReadings)
		{
			std::vector<T>::const_iterator first = humidity.data.begin();
			std::vector<T>::const_iterator last = humidity.data.begin() + noReadings;
			result.data.assign(first, last);
		}
		else
		{
			std::vector<T>::const_iterator first = humidity.data.begin();
			std::vector<T>::const_iterator last = humidity.data.end();
			result.data.assign(first, last);
			std::vector<T> temp = fileReader.ReadData<int>("humidity", noReadings - humidity.data.size());
			result.data.insert(result.data.end(), temp.begin(), temp.end());
		}
		return result;
	}
	
	template<typename T, typename std::enable_if<std::is_same<T, double>::value, int>::type = 0>
	Data<T> GetData(int noReadings)
	{
		Data<T> result;
		if (temperature.data.size() >= noReadings)
		{
			std::vector<T>::const_iterator first = temperature.data.begin();
			std::vector<T>::const_iterator last = temperature.data.begin() + noReadings;
			result.data.assign(first, last);
		}
		else
		{
			std::vector<T>::const_iterator first = temperature.data.begin();
			std::vector<T>::const_iterator last = temperature.data.end();
			result.data.assign(first, last);
			std::vector<T> temp = fileReader.ReadData<double>("temperature", noReadings - temperature.data.size());
			result.data.insert(result.data.end(), temp.begin(), temp.end());
		}
		return result;
	}
	
	template<typename T, typename std::enable_if<std::is_same<T, int>::value, int>::type = 0>
	void PutData(T data)
	{
		//std::lock_guard<std::mutex> humidityLock(humidityMutex);
		humidity.data.push_back(data);		
		if (humidity.data.size() >= cacheSize)
		{
			WriteHumidityToFile();
		}
	}

	template<typename T, typename std::enable_if<std::is_same<T, double>::value, int>::type = 0>
	void PutData(T data)
	{
		//std::lock_guard<std::mutex> temperatureLock(temperatureMutex);
		temperature.data.push_back(data);
		if (temperature.data.size() >= cacheSize)
		{
			WriteTemperatureToFile();
		}
	}
};
#endif