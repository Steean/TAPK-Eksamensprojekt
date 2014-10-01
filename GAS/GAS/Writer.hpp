#include "DataObjects.hpp"

class Writer
{
public:
	template <typename T>
	void WriteData(const Data<T>& dataObj);
	virtual void WriteSettings(const Settings& settingsObj) = 0;
};