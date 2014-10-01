#include <memory>
#include <ostream>
#include "DataObjects.hpp"

class Writer
{
public:
	template <typename T>
	void WriteData(const Data<T>& dataObj);
	virtual void WriteSettings(const Settings& settingsObj) = 0;
private:
	std::shared_ptr<std::ostream> _stream;
};