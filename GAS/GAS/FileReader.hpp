#include <fstream>
#include <iostream>
#include <string>
#include "DataObjects.hpp"

class Reader
{
public:
	template <typename T>
	Data<T> ReadData();
};

class FileReader : Reader
{
public:
	FileReader(std::string filepath);

	template<typename T, typename std::enable_if<std::is_same<T,int>::value, int>::type = 0>
	Data<T> ReadData()
	{
		Data<T> result;
		std::string line = "";

		std::ifstream stream;
		stream.open(_filePath);

		while (std::getline(stream, line, ';'))
		{
			result.data.push_back(std::stoi(line.c_str()));
		}
		stream.close();
		
		return result;
	}

	template<typename T, typename std::enable_if<std::is_same<T, double>::value, double>::type = 0>
	Data<T> ReadData()
	{
		Data<T> result;
		std::string line = "";

		std::ifstream stream;
		stream.open(_filePath);

		while (std::getline(stream, line, ';'))
		{
			result.data.push_back(std::atof(line));
		}
		stream.close();

		return result;
	}
	
private:
	std::string _filePath;
};