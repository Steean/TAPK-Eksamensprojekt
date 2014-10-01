#include "FileWriter.hpp"

int main()
{
	FileWriter fw("test.txt");
	std::vector<int> vect {1,2,3,4,5,6,7,8,9,0};
	Data<int> dat;
	dat.data = vect;
	fw.WriteData(dat);
}