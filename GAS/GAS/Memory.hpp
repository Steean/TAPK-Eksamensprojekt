#include <mutex>
#include <furure>
#include "DataObjects.hpp"
#include "FileWriter.hpp"
#include "FileReader.hpp"

class Memory
{
private:
	Data<double> temperature;
	Data<int> humidity;
	int dataThreshold;
	Details::FileWriter fileWriter;
	Details::FileReader fileReader;
	void ThresholdCheck();
	void WriteToFile();
	std::mutex temperatureMutex;
	std::mutex humidityMutex;
public:
	Memory(int threshold);

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
	std::future<Data<T>> GetData(int noReadings)
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
		std::lock_guard<std::mutex> humidityLock(humidityMutex);
		humidity.data.push_back(data);		
		if (humidity.data.size() >= dataThreshold)
		{
			WriteToFile();
		}
	}

	template<typename T, typename std::enable_if<std::is_same<T, double>::value, int>::type = 0>
	void PutData(T data)
	{
		std::lock_guard<std::mutex> temperatureLock(temperatureMutex);
		temperature.data.push_back(data);
		if (temperature.data.size() >= dataThreshold)
		{
			WriteToFile();
		}
	}
};