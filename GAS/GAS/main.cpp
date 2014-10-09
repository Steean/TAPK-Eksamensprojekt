#include <iterator>
#include <chrono>
#include <thread>
#include <utility>
#include "WindowWater.hpp"
#include "Memory.hpp"
#include "GASSystem.hpp"
#include "TemperatureSensor.hpp"
#include "IntervalTimer.hpp"

int main()
{
	/*Details::FileWriter fw;
	std::vector<double> vect {1.1,2.2,3.3,4.4,5.5};
	Data<double> dat;
	dat.data = vect;*/
	//fw.WriteData("temperature", dat);

	//Memory mem(2);
	//
	//mem.PutData<double>(1.2);
	//mem.PutData<double>(3.4);
	//mem.PutData<double>(5.6);	

	//std::this_thread::sleep_for(std::chrono::seconds(3));

	//auto test = mem.GetData<double>(1);
	//auto test2 = mem.GetData<double>(2);
	//auto test3 = mem.GetData<double>(3);
/*
	IntervalTimer timer;	
	TemperatureSensor tempsens(&timer);
	HumiditySensor humsens(&timer);
	GASSystem system(&tempsens, &humsens); 

	timer.Start(std::chrono::milliseconds(2000));
	
	std::this_thread::sleep_for(std::chrono::seconds(10));

	timer.Stop();*/

	Memory mem();
	Data<double> dat;
	std::vector<double> dat_vect {2,2.3,3.4,4.5,5.6};
	dat.data = dat_vect;

	Details::FileWriter fw;

//	fw.WriteData("test", std::move(dat));


	std::cout << "DEBUG FUCKING POINT!";

	/*Settings settings(30.3, 20.0, 80, 20, 60);
	settings.save("settings.xml");

	Settings tmp;
	tmp.load("settings.xml");

	auto i = 0;*/

	//FileReader fr;
	//Data<double> test = fr.ReadData<double>("test2",2);

	//std::cout << "DEBUG FUCKING POINT!";

	//Memory mem;
	//auto temp = mem.GetData<double>();

	//std::cout << "DEBUG FUCKING POINT!";


}