#include "Booking.h"


int Booking::current_id = 0;

Booking::Booking(Customer* _customer, Accommodations* _accommodation, bool _activity, bool _sports, bool _bicyle, bool _swim):
	activityPass(_activity), sportsPass(_sports), bicycleRent(_bicyle), swimmingPass(_swim),customer(_customer)
{
	id = current_id++;
	addAccommodation(_accommodation);
}

Booking::~Booking()
{
	for (Accommodations* i : accommodation)
	{
		i->setBooked(false);
	}
	customer->setBooked(false);
}



const int Booking::getID() const
{
	return id;
}

const bool Booking::getActivityPass() const
{
	return activityPass;
}
const bool Booking::getSportsPass() const
{
	return sportsPass;
}
const bool Booking::getBicycleRent() const
{
	return bicycleRent;
}
const bool Booking::GetSwimmingPass() const
{
	return swimmingPass;
}
const Customer Booking::getCustomer() const
{
	return *customer;
}
const std::vector<Accommodations*> Booking::getAccommodation() const
{
	return accommodation;
}

void Booking::setCustomer(Customer* _customer)
{
	customer = _customer;
}
void Booking::addAccommodation(Accommodations* _accommodation)
{
	_accommodation->setBooked(true);
	customer->setBooked(true);
	accommodation.push_back(_accommodation);
}
void Booking::setActivityPass(bool _activity)
{
	activityPass = _activity;
}
void Booking::setSportsPass(bool _sportsPass)
{
	sportsPass = _sportsPass;
}
void Booking::setBicycleRent(bool _bicycleRent)
{
	bicycleRent = _bicycleRent;
}
void Booking::setSwimmingPass(bool _swimmingPass)
{
	swimmingPass = _swimmingPass;
}

const std::string Booking::toString() const
{
	std::string str = "Customer: " + customer->getMail() + "\n";
	str += "Booked Accommodations: \n";
	for (const Accommodations* i : getAccommodation())
	{
		str += i->toString();
	}
	return str;
}