#include "DataObjects.hpp"
#include <memory>
#include <ostream>

class Writer
{
public:
	template <typename T>
	void WriteData(const Data<T>& dataObj);
	virtual void WriteSettings(const Settings& settingsObj) = 0;
};

class FileWriter : Writer
{
public:
	FileWriter(std::string filePath);
	std::ofstream& operator<<(const Settings& set);
	template <typename T>
	void WriteData(const Data<T>& dataObj)
	{
		std::ofstream stream;

		stream.open(_filePath);
		std::copy(dataObj.data.begin(), dataObj.data.end(), std::ostream_iterator<T>(stream, ";"));

		stream.close();
	}

private:
	std::string _filePath;
};