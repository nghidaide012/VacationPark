#pragma once
#include <string>
#include <vector>
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
	std::string name;
	std::string address;
	std::string mail;
	int permission;
	bool isBooked = false;


public:
	Customer(std::string="", std::string="", std::string="", int=0);

	void setBooked(bool);
	void setName(std::string );
	void setAddress(std::string );
	void setMail(std::string );
	void setPermission(int);
	const std::string getName() const;
	const std::string getAddress() const;
	const std::string getMail() const;
	const std::string toString() const;
	const bool getBooked() const;
	const int getPermission() const;
};

#endif // !USER_H