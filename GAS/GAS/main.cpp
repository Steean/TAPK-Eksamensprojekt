#include <iterator>
#include <chrono>
#include <thread>
#include <utility>
#include <iostream>
#include <exception>
#include <conio.h>
#include "WindowWater.hpp"
#include "Memory.hpp"
#include "GASSystem.hpp"
#include "TemperatureSensor.hpp"
#include "IntervalTimer.hpp"

void Welcome()
{
	system("cls");
	std::cout << "Welcome to your Greenhouse Automation System - You now have the following options: " << std::endl;
	std::cout << "1. Configure greenhouse" << std::endl;
	std::cout << "2. Start greenhouse automation" << std::endl;
	std::cout << "3. Exit" << std::endl;
}

void ConfigureGreenhouse()
{
	Settings set;
	system("cls");
	std::cout << "Max temperature (double): " << std::endl;
	std::cin >> set.maxTemperature;
	std::cout << "Min temperature (double): " << std::endl;
	std::cin >> set.minTemperature;
	std::cout << "Max humidity (int): " << std::endl;
	std::cin >> set.maxHumidity;
	std::cout << "Min humidity (int): " << std::endl;
	std::cin >> set.minHumidity;
	std::cout << "Cache size (int) :" << std::endl;
	std::cin >> set.cacheSize;
	set.save("settings");
}

void StartGreenhouse()
{
	system("cls");
	
	std::cout << "Your Greenhouse automation system is now running. Press any key to stop it and the return to the menu." << std::endl;

	Settings setting;
	try
	{
		setting.load("settings");
	}
	catch (std::exception e)
	{
		std::cout << "No settings file found, please configure your system first." << std::endl;
		ConfigureGreenhouse();
	}
	IntervalTimer timer;
	TemperatureSensor tempSens(&timer);
	HumiditySensor humSens(&timer);
	GASSystem system(&tempSens, &humSens, setting);
	timer.Start(std::chrono::milliseconds(500));

	while (true)
	{
		if (kbhit()) { break; }
	}

	timer.Stop();
}

int main()
{
	bool running = true;
	while (running)
	{
		Welcome();

		int selection = 0;
		std::cin >> selection;

		switch (selection)
		{
		case 1:
			ConfigureGreenhouse();
			break;
		case 2:
			StartGreenhouse();
			break;
		case 3:
			return 0;			
			break;
		default:
			std::cout << "Invalid selection" << std::endl;
			break;
		}
	}
}