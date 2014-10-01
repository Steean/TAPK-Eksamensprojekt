#include <fstream>
#include <iterator>
#include <iomanip>
#include "FileWriter.hpp"

FileWriter::FileWriter(std::string filepath) : _filePath(filepath) {};

std::ofstream& operator<<(std::ofstream& os, const Settings& set)
{
	//Make sure that .0 doesn't get removed from the double values
	os << std::setprecision(1) << std::fixed;
		
	os << "maxTemperature: " << set.maxTemperature << "\n";
	os << "minTemperature: " << set.minTemperature << "\n";
	os << "maxHumidity: " << set.maxHumidity << "\n";
	os << "minHumidity: " << set.minHumidity << "\n";
	os << "interval: " << set.interval << "\n";

	return os;
}

void FileWriter::WriteSettings(const Settings& settingsObj)
{
	std::ofstream stream;

	stream.open("Settings");
	stream << settingsObj;
	stream.close();
};