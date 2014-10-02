#include "DataObjects.hpp"
#include <memory>
#include <ostream>

class Writer
{
public:
	template <typename T>
	void WriteData(const std::string& filepath, const Data<T>& dataObj);
};

class FileWriter : Writer
{
public:
	std::ofstream& operator<<(const Settings& set);
	template <typename T>
	void WriteData(const std::string& filepath, const Data<T>& dataObj)
	{
		std::ofstream stream;

		stream.open(filepath);
		std::copy(dataObj.data.begin(), dataObj.data.end(), std::ostream_iterator<T>(stream, ";"));

		stream.close();
	}
};