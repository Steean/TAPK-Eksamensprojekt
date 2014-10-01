//#include "Writer.hpp"

#include <memory>
#include <ostream>
#include "DataObjects.hpp"

class FileWriter
{
public:
	FileWriter(std::string filePath);
	void WriteData(const Data<int>& dataObj);
	void WriteSettings(const Settings& settingsObj);
private:
	std::shared_ptr<std::ofstream> _stream;
	std::string _filePath;
};