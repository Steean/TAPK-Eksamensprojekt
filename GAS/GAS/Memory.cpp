#include "Memory.hpp"

Memory::Memory(int threshold)
{
	dataThreshold = threshold;
}

void Memory::WriteToFile()
{
	fileWriter.WriteData<double>("temperature", temperature);
	fileWriter.WriteData<int>("humidity", humidity);

	temperature.data.clear();
	humidity.data.clear();
}