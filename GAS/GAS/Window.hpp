#include <iostream>
#include <string>
#include <boost\statechart\state_machine.hpp>
#include <boost\statechart\simple_state.hpp>
#include <boost\statechart\transition.hpp>

namespace sc = boost::statechart;

enum state 
{	
	Water,
	Window
};

//Events
struct MaxTemperatureThreshold : sc::event <MaxTemperatureThreshold> {};
struct MinTemperatureThreshold : sc::event <MinTemperatureThreshold> {};
struct MaxHumidityThreshold : sc::event <MaxHumidityThreshold> {};
struct MinHumidityThreshold : sc::event <MinHumidityThreshold> {};

//Top-level state and machine definition
struct GAS;
struct Machine : sc::state_machine<Machine, GAS> {};
struct On;
struct Off;
struct Open;
struct Close;

struct GAS : sc::simple_state<GAS, Machine, boost::mpl::list<Off, Close>> {};

struct Off : sc::simple_state <Off, GAS::orthogonal<state::Water>>
{
	Off()
	{
		std::cout << "Water Off" << std::endl;
	}
	typedef sc::transition<MinHumidityThreshold, On> reactions;
};

struct On : sc::simple_state <On, GAS::orthogonal<state::Water>>
{
	On()
	{
		std::cout << "Water On" << std::endl;
	}
	typedef sc::transition<MaxHumidityThreshold, Off> reactions;
};

struct Close : sc::simple_state <Close, GAS::orthogonal<state::Window>>
{
	Close()
	{
		std::cout << "Window Close" << std::endl;
	}
	typedef sc::transition<MaxTemperatureThreshold, Open> reactions;
};

struct Open : sc::simple_state <Open, GAS::orthogonal<state::Window>>
{
	Open()
	{
		std::cout << "Window Open" << std::endl;
	}
	typedef sc::transition<MinTemperatureThreshold, Close> reactions;
};