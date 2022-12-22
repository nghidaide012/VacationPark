#pragma once
#include "ParcService.h"
#include "Accommodations.h"
#include "Cabin.h"
#include "HotelRoom.h"
#ifndef PARCS_H
#define PARCS_H

class Parcs
{
	int id;
	static int current_id;
	std::string name;
	std::string address;
	ParcService services;
	std::vector<Accommodations*> accommodations;
	int Parc_region_id;
public:
	Parcs(int,std::string, std::string, ParcService);

	const int getRegionID() const;
	const int getID() const;
	const std::string getName() const;
	const std::string getAddress() const;
	const ParcService getService() const;
	const std::vector<Accommodations*> getAccommodations() const;
	void deleteAccommodation(int _id);
	void setRegionID(int);
	void setName(std::string);
	void setAddress(std::string);
	void setService(bool, bool, bool, bool, bool, bool);
	void addAccommodations(Accommodations*);
	const std::string toString() const;

};

#endif