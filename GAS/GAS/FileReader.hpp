#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "DataObjects.hpp"

class Reader
{
public:
	template <typename T>
	Data<T> ReadData(const std::string& filepath);
};

class FileReader : Reader
{
public:
	template<typename T, typename std::enable_if<std::is_same<T,int>::value, int>::type = 0>
	std::vector<T> ReadData(const std::string& filepath, int noReadings)
	{
		std::vector<T> result;
		std::string reading = "";
		int index = 1;

		std::ifstream stream;
		stream.open(filepath);

		while (std::getline(stream, reading, ';') && index <= noReadings)
		{
			result.push_back(std::stoi(reading.c_str()));
			index++;
		}
		stream.close();

		return result;
	}

	template<typename T, typename std::enable_if<std::is_same<T, double>::value, int>::type = 0>
	std::vector<T> ReadData(const std::string& filepath, int noReadings)
	{
		std::vector<T> result;
		std::string reading = "";
		int index = 1;

		std::ifstream stream;
		stream.open(filepath);

		while (std::getline(stream, reading, ';') && index <= noReadings)
		{
			result.push_back(std::atof(reading.c_str()));
			index++;
		}
		stream.close();

		return result;
	}
};