#include "LuxuryLevel.h"


LuxuryLevel::LuxuryLevel(std::string _kind, bool _bbq, bool _surrondSystem, bool _cleaning, bool _breakfast):
	accommodationKind(_kind), bbq(_bbq), surrondSystem(_surrondSystem), cleaning(_cleaning), breakfast(_breakfast) {}

const bool LuxuryLevel::getBBQ() const
{
	return bbq;
}
const bool LuxuryLevel::getSurrondSystem() const
{
	return surrondSystem;
}
const bool LuxuryLevel::getCleaning() const
{
	return cleaning;
}
const bool LuxuryLevel::getBreakfast() const
{
	return breakfast;
}

const std::string LuxuryLevel::getAccommodationKind() const
{
	return accommodationKind;
}

void LuxuryLevel::setBBQ(bool _bbq)
{
	bbq = _bbq;
}
void LuxuryLevel::setSurrondSystem(bool _surrond)
{
	surrondSystem = _surrond;
}
void LuxuryLevel::setCleaning(bool _clean)
{
	cleaning = _clean;
}
void LuxuryLevel::setBreakfast(bool _breakfast)
{
	breakfast = _breakfast;
}
void LuxuryLevel::setAccommodationKind(std::string _kind)
{
	accommodationKind = _kind;
}

const std::string LuxuryLevel::toString() const
{
	return "BBQ: " + std::to_string(getBBQ()) + "\n" +
		"Surrond System: " + std::to_string(getSurrondSystem()) + "\n" +
		"Cleaning service: " + std::to_string(getCleaning()) + "\n" +
		"Breakfast service: " + std::to_string(getBreakfast()) + "\n";
}