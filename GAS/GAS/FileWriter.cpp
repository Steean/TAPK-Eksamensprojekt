#include <fstream>
#include <iterator>
#include "FileWriter.hpp"

FileWriter::FileWriter(std::string filepath) : _filePath(filepath) {};

void FileWriter::WriteData(const Data<int>& dataObj)
{
	_stream->open(_filePath);

	std::copy(dataObj.data.begin(), dataObj.data.end(), std::ostream_iterator<int>(*_stream, ";"));

	_stream->close();
};

void FileWriter::WriteSettings(const Settings& settingsObj)
{

};