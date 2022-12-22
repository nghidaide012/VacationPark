#pragma once
#include <iomanip>
#include "Accommodations.h"

#ifndef HOTELROOM_H
#define HOTELROOM_H
class HotelRoom : public Accommodations
{

	int bedRooms;
	int childBeds;
	int floor;
public:
	HotelRoom(std::string,int,int,int,std::string,int, int, int, bool, bool, bool, bool, bool);
	const int getFloor() const;
	virtual const int getBedrooms() const override;
	const int getChildBeds() const;
	void setFloor(int);
	virtual void setBedrooms(int) override;
	void setChildBeds(int);
	const std::string toString() const;
};

#endif