#include "FileWriter.hpp"
#include "FileReader.hpp"
#include <fstream>
#include <iterator>

int main()
{
	FileWriter fw("test");
	std::vector<double> vect {1.1,2.2,3.3,4.4};
	Data<double> dat;
	dat.data = vect;
	fw.WriteData(dat);

	Settings settings(30.3, 20.0, 80, 20, 60);
	fw.WriteSettings(settings);

	FileReader fr("test");
	Data<double> test = fr.ReadData<double>();

	std::cout << "er vi her";
}