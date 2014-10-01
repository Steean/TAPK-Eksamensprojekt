#include <vector>

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
};
