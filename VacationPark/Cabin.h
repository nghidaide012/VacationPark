#pragma once
#include "Accommodations.h"
#ifndef CABIN_H
#define CABIN_H
class Cabin : public Accommodations
{

	int bedRooms;

public:
	Cabin(std::string,int,int, int,std::string, int, bool, bool, bool, bool, bool);
	virtual const int getBedrooms() const override;
	virtual void setBedrooms(int) override;

	const std::string toString() const;
};
#endif
