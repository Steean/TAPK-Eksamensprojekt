#include <fstream>
#include <iterator>
#include "FileWriter.hpp"
#include "FileReader.hpp"

int main()
{
	/*FileWriter fw("test");
	std::vector<double> vect {1.1,2.2,3.3,4.4};
	Data<double> dat;
	dat.data = vect;
	fw.WriteData(dat);*/

	Settings settings(30.3, 20.0, 80, 20, 60);
	settings.save("settings.xml");

	Settings tmp;
	tmp.load("settings.xml");

	auto i = 0;

	/*FileReader fr("test");
	Data<double> test = fr.ReadData<double>();

	std::cout << "DEBUG FUCKING POINT!";*/
}