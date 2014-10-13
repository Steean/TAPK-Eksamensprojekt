#ifndef DATAOBJECTS_HPP
#define DATAOBJECTS_HPP

#include <vector>
#include <utility>
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\xml_parser.hpp>

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
	int cacheSize;

	Settings(double maxTemp = 20.0, double minTemp = 5.0, int maxHum = 90, int minHum = 10, int cachesize = 2)
		: maxTemperature(maxTemp), minTemperature(minTemp), maxHumidity(maxHum), minHumidity(minHum), cacheSize(cachesize) {}

	void load(const std::string& filename)
	{
		using boost::property_tree::ptree;
		ptree pt;

		boost::property_tree::xml_parser::read_xml(filename, pt);

		maxTemperature = pt.get<double>("Settings.maxTemperature");
		minTemperature = pt.get<double>("Settings.minTemperature");
		maxHumidity = pt.get<int>("Settings.maxHumidity");
		minHumidity = pt.get<int>("Settings.minHumidity");
		cacheSize = pt.get<int>("Settings.cacheSize");
	}
	void save(const std::string& filename)
	{
		using boost::property_tree::ptree;
		ptree pt;

		pt.put("Settings.maxTemperature", maxTemperature);
		pt.put("Settings.minTemperature", minTemperature);
		pt.put("Settings.maxHumidity", maxHumidity);
		pt.put("Settings.minHumidity", minHumidity);
		pt.put("Settings.cacheSize", cacheSize);

		boost::property_tree::xml_parser::write_xml(filename, pt);
	}
};
#endif