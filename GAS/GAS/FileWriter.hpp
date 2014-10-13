#ifndef FILEWRITER_HPP
#define FILEWRITER_HPP

#include "DataObjects.hpp"
#include <memory>
#include <ostream>
#include <iterator>
#include <fstream>
#include <exception>

namespace Details
{

class Writer
{
public:
	template <typename T>
	void WriteData(const std::string& filepath, Data<T>& dataObj);
};

class FileWriter : Writer
{
public:
	std::ofstream& operator<<(const Settings& set);
	template <typename T>
	void WriteData(std::string& filepath, Data<T>& dataObj)
	{
		std::ofstream stream;

		stream.open(filepath, std::ios::out | std::ios::app);
		std::copy(dataObj.data.begin(), dataObj.data.end(), std::ostream_iterator<T>(stream, ";"));
	}
};

}
#endif