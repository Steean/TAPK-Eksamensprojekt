//#include "Writer.hpp"

#include <memory>
#include <ostream>
#include "DataObjects.hpp"

class FileWriter
{
public:
	FileWriter(std::string filePath);
	template <typename T>
	void WriteData(const Data<T>& dataObj)
	{
		std::ofstream stream;

		stream.open(_filePath);
		std::copy(dataObj.data.begin(), dataObj.data.end(), std::ostream_iterator<T>(stream, ";"));

		stream.close();
	}
	void WriteSettings(const Settings& settingsObj);
private:
	std::string _filePath;
};