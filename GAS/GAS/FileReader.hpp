#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "DataObjects.hpp"

#ifndef FILEREADER_HPP
#define FILEREADER_HPP

namespace Details
{

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
		std::stack<T> temp;
		std::vector<T> result;
		std::string reading = "";		

		std::ifstream stream;
		stream.open(filepath);

		while (std::getline(stream, reading, ';'))
		{
			temp.push(std::stoi(reading.c_str()));			
		}
		stream.close();

		for (int i = 0; i < noReadings; i++)
		{
			result.push_back(temp.top());
			temp.pop();
		}

		return result;
	}

	template<typename T, typename std::enable_if<std::is_same<T, double>::value, int>::type = 0>
	std::vector<T> ReadData(const std::string& filepath, int noReadings)
	{
		std::stack<T> temp;
		std::vector<T> result;
		std::string reading = "";		

		std::ifstream stream;
		stream.open(filepath);

		while (std::getline(stream, reading, ';'))
		{
			temp.push(std::atof(reading.c_str()));			
		}
		stream.close();

		for (int i = 0; i < noReadings; i++)
		{
			std::cout << temp.top() << std::endl;
			result.push_back(temp.top());
			temp.pop();
		}

		return result;
	}
};

}

#endif