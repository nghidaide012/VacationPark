#include "Accommodations.h"

int Accommodations::current_id = 1;

Accommodations::Accommodations(std::string _is, int _id, int _nrPeople, int _size, std::string _room, bool _bathroomWithBath, bool _bbq, bool _surrond, bool _clean, bool _breakfast) :
	nrPeople(_nrPeople), size(_size), bathroomWithBath(_bathroomWithBath), RoomID(_room), Parc_id(_id), isWhich(_is), luxuryLevel(LuxuryLevel(_is, _bbq, _surrond, _clean, _breakfast))
{
	id = current_id++;
}

const std::string Accommodations::getIswhich() const
{
	return isWhich;
}
const int Accommodations::getParcID() const
{
	return Parc_id;
}
const std::string Accommodations::getRoomID() const
{
	return RoomID;
}
const int Accommodations::getID() const
{
	return id;
}
const int Accommodations::getNrPeople() const
{
	return nrPeople;
}
const bool Accommodations::getBooked() const
{
	return isBooked;
}
const bool Accommodations::getBathroomWithBath() const
{
	return bathroomWithBath;
}
const int Accommodations::getSize() const
{
	return size;
}
void Accommodations::setIswhich(std::string _is)
{
	isWhich = _is;
}
void Accommodations::setParcID(int _id)
{
	Parc_id = _id;
}

void Accommodations::setBooked(bool _booked)
{
	isBooked = _booked;
}
void Accommodations::setRoomID(std::string _room)
{
	RoomID = _room;
}

void Accommodations::setSize(int _size)
{
	size = _size;
}
void Accommodations::setNrPeople(int _number)
{
	nrPeople = _number;
}
void Accommodations::setBathroomWithBath(bool _bath)
{
	bathroomWithBath = _bath;
}
void Accommodations::setLuxuryLevel(std::string _is, bool _bbq, bool _surrond, bool _clean, bool _breakfast)
{
	luxuryLevel = LuxuryLevel(_is, _bbq, _surrond, _clean, _breakfast);
}
const LuxuryLevel Accommodations::getLuxuryLevel() const
{
	return luxuryLevel;
}

const std::string Accommodations::toString() const
{
	return "Number of People: " + std::to_string(getNrPeople()) + "\n"
		+ "Size: " + std::to_string(getSize()) + "\n" +
		"Bathroom with bath: " + std::to_string(getBathroomWithBath()) + "\n" +
		luxuryLevel.toString();

}
