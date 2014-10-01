#include "FileWriter.hpp"
#include <fstream>
#include <iterator>

int main()
{
	FileWriter fw("test");
	std::vector<double> vect {1.1,2.2,3.3,4.4};
	Data<double> dat;
	dat.data = vect;
	fw.WriteData(dat);
}