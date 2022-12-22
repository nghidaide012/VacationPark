#pragma once
#include "Parcs.h"
#include "Customer.h"
#ifndef VACATIONPARCS_H
#define VACATIONPARCS_H

class VacationParcs
{
	int id;
	static int current_id;
	std::string name;
	std::string regions;
	std::vector<Parcs*> parcs;

public:
	VacationParcs(std::string, std::string);
	const int getID() const;
	const std::string getName() const;
	const std::string getRegions() const;
	const std::vector<Parcs*> getParcs() const;

	void deleteParc(int);
	void setName(std::string);
	void setRegion(std::string);
	void addParcs(Parcs*);

	const std::string toString() const;
};

#endif
