#include <vector>
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\xml_parser.hpp>

#ifndef DATAOBJECTS_HPP
#define DATAOBJECTS_HPP

template <typename T>
struct Data
{
	std::vector<T> data;
};

struct Settings
{
	double maxTemperature;
	double minTemperature;
	int maxHumidity;
	int minHumidity;
	int interval;

	Settings(double maxTemp = 0.0, double minTemp = 0.0, int maxHum = 0, int minHum = 0, int i = 0)
		: maxTemperature(maxTemp), minTemperature(minTemp), maxHumidity(maxHum), minHumidity(minHum), interval(i) {}

	void load(const std::string& filename)
	{
		using boost::property_tree::ptree;
		ptree pt;

		boost::property_tree::xml_parser::read_xml(filename, pt);

		maxTemperature = pt.get<double>("Settings.maxTemperature");
		minTemperature = pt.get<double>("Settings.minTemperature");
		maxHumidity = pt.get<int>("Settings.maxHumidity");
		minHumidity = pt.get<int>("Settings.minHumidity");
		interval = pt.get<int>("Settings.interval");
	}
	void save(const std::string& filename)
	{
		using boost::property_tree::ptree;
		ptree pt;

		pt.put("Settings.maxTemperature", maxTemperature);
		pt.put("Settings.minTemperature", minTemperature);
		pt.put("Settings.maxHumidity", maxHumidity);
		pt.put("Settings.minHumidity", minHumidity);
		pt.put("Settings.interval", interval);

		boost::property_tree::xml_parser::write_xml(filename, pt);
	}
};
#endif