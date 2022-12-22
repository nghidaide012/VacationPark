#include "Customer.h"


Customer::Customer(std::string _name, std::string _address, std::string _mail, int _isWho):
	name(_name), address(_address), mail(_mail), permission(_isWho) {

}

void Customer::setName(std::string _name)
{
	name = _name;
}
void Customer::setPermission(int _per)
{
	permission = _per;
}
void Customer::setAddress(std::string _address)
{
	address = _address;
}
void Customer::setMail(std::string _mail)
{
	mail = _mail;
}
void Customer::setBooked(bool _booked)
{
	isBooked = _booked;
}
const int Customer::getPermission() const
{
	return permission;
}
const bool Customer::getBooked() const
{
	return isBooked;
}
const std::string Customer::getName() const
{
	return name;
}
const std::string Customer::getAddress() const
{
	return address;
}
const std::string Customer::getMail() const
{
	return mail;
}
const std::string Customer::toString() const
{
	return "Name: " + getName() + "\n"
		+ "Address: " + getAddress() + "\n"
		+ "email" + getMail() + "\n";
}