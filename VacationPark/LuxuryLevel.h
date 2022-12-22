
#pragma once
#include<string>
#ifndef LUXURYLEVEL_H
#define LUXURYLEVEL_H


class LuxuryLevel
{
	bool bbq;
	bool surrondSystem;
	bool breakfast;
	bool cleaning;
	std::string accommodationKind;
public:
	LuxuryLevel(std::string, bool, bool, bool, bool);
	const bool getBBQ() const;
	const bool getSurrondSystem() const;
	const bool getCleaning() const;
	const bool getBreakfast() const;
	const std::string getAccommodationKind() const;
	void setBBQ(bool);
	void setSurrondSystem(bool);
	void setCleaning(bool);
	void setBreakfast(bool);
	void setAccommodationKind(std::string);
	const std::string toString() const;

};
#endif // LUXURYLEVEL_H
