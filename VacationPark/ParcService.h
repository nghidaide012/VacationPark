#pragma once
#include <string>

#ifndef PARCSERVICE_H
#define PARCSERVICE_H

class ParcService
{
	bool subtropicSwim;
	bool sportsInfras;
	bool bowling;
	bool bicycle;
	bool childrensParadise;
	bool waterBikes;

public:
	ParcService(bool, bool, bool, bool, bool, bool);


	const bool getSubtropicSwimmingPool() const;
	const bool getSport() const;
	const bool getBowling() const;
	const bool getBicyle() const;
	const bool getChildren() const;
	const bool getWaterBikes() const;

	void setSubtropicSwimmingPool(bool);
	void setSport(bool);
	void setBowling(bool);
	void setBicycle(bool);
	void setChildren(bool);
	void setWaterBikes(bool);

	const std::string toString() const;
};

#endif