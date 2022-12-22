#include <vector>
#include <string>
#include "LuxuryLevel.h"
#pragma once
#ifndef ACCOMMODATIONS_H
#define ACCOMMODATIONS_H



class Accommodations
{
protected:
	int id;
	static int current_id;
	int nrPeople;
	int size;
	bool bathroomWithBath;
	std::string RoomID;
	LuxuryLevel luxuryLevel;
	bool isBooked = false;
	int Parc_id;
	std::string isWhich;
public:
	Accommodations(std::string , int, int, int, std::string, bool, bool, bool, bool , bool );
	const std::string getIswhich() const;
	const int getParcID() const;
	const int getID() const;
	const int getSize() const;
	const bool getBooked() const;
	virtual const int getFloor() const { return 0; }
	virtual const int getChildBeds() const { return 0; }

	const int getNrPeople() const;
	const std::string getRoomID() const;
	const bool getBathroomWithBath() const;
	const LuxuryLevel getLuxuryLevel() const;
	void setLuxuryLevel(std::string,bool, bool, bool, bool);
	virtual void setFloor(int){};
	virtual void setChildBeds(int){};
	void setIswhich(std::string);
	void setParcID(int);
	void setRoomID(std::string);
	void setBooked(bool);
	void setSize(int);
	void setNrPeople(int);
	
	void setBathroomWithBath(bool);
	virtual const int getBedrooms() const=0;
	virtual void setBedrooms(int)=0;
	virtual const std::string toString() const;

};

#endif