#include "ParcService.h"

ParcService::ParcService(bool _swim, bool _sport, bool _bowling, bool _bicycle, bool _children, bool _water):
	subtropicSwim(_swim), sportsInfras(_sport), bowling(_bowling), bicycle(_bicycle), childrensParadise(_children), waterBikes(_water) {}



const bool ParcService::getSubtropicSwimmingPool() const
{
	return subtropicSwim;
}
const bool ParcService::getSport() const {
	return sportsInfras;
}
const bool ParcService::getBowling() const {
	return bowling;
}
const bool ParcService::getBicyle() const {
	return bicycle;
}
const bool ParcService::getChildren() const {
	return childrensParadise;
}
const bool ParcService::getWaterBikes() const {
	return waterBikes;
}
void ParcService::setSubtropicSwimmingPool(bool _swim)
{
	subtropicSwim = _swim;
}

void ParcService::setSport(bool _sport) {
	sportsInfras = _sport;
}
void ParcService::setBowling(bool _bowling) {
	bowling = _bowling;
}
void ParcService::setBicycle(bool _bicycle) {
	bicycle = _bicycle;
}
void ParcService::setChildren(bool _children) {
	childrensParadise = _children;
}
void ParcService::setWaterBikes(bool _water) {
	waterBikes = _water;
}
const std::string ParcService::toString() const
{
	return "Subtropic SwimmingPool: " + std::to_string(getSubtropicSwimmingPool()) + "\n" +
		"Sports infrastructured: " + std::to_string(getSport()) + "\n" +
		"Bowling Alley: " + std::to_string(getBowling()) + "\n" +
		"Bicyle Rent: " + std::to_string(getBicyle()) + "\n" +
		"Children Paradise: " + std::to_string(getChildren()) + "\n" +
		"Water Bikes: " + std::to_string(getWaterBikes()) + "\n";
		
}
