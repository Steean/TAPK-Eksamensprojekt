#include <iterator>
#include <chrono>
#include <thread>
#include "Window.hpp"
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

	IntervalTimer timer;	
	TemperatureSensor tempsens(&timer);
	HumiditySensor humsens(&timer);
	GASSystem system(&tempsens, &humsens); 

	timer.Start(std::chrono::milliseconds(2000));

	
	std::this_thread::sleep_for(std::chrono::seconds(10));

	timer.Stop();

	std::cout << "DEBUG FUCKING POINT!";

	

	/*Settings settings(30.3, 20.0, 80, 20, 60);
	settings.save("settings.xml");

	Settings tmp;
	tmp.load("settings.xml");

	auto i = 0;*/

	//Machine machine;
	//machine.initiate();

	//machine.process_event(MaxTemperatureThreshold());
	//machine.process_event(MinHumidityThreshold());

	//FileReader fr;
	//Data<double> test = fr.ReadData<double>("test2",2);

	//std::cout << "DEBUG FUCKING POINT!";

	//Memory mem;
	//auto temp = mem.GetData<double>();

	//std::cout << "DEBUG FUCKING POINT!";
}