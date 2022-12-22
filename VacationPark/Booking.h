#pragma once
#include <string>
#include <vector>
#include "Customer.h"
#include "Accommodations.h"
#ifndef BOOKING_H
#define BOOKING_H
class Booking
{
	int id;
	static int current_id;
	Customer* customer;
	std::vector<Accommodations*> accommodation;
	bool activityPass;
	bool sportsPass;
	bool bicycleRent;
	bool swimmingPass;
	int acco_id;
	int customer_id;
public:

	Booking(Customer*,Accommodations*, bool = false,bool  = false, bool  = false, bool  = false);
	~Booking();

	const int getID() const;
	const Customer getCustomer() const;
	const std::vector<Accommodations*> getAccommodation() const;
	const bool getActivityPass() const;
	const bool getSportsPass() const;
	const bool getBicycleRent() const;
	const bool GetSwimmingPass() const;

	void setCustomer(Customer*);
	void addAccommodation(Accommodations*);
	void setActivityPass(bool);
	void setSportsPass(bool);
	void setBicycleRent(bool);
	void setSwimmingPass(bool);
	const std::string toString() const;

};

#endif