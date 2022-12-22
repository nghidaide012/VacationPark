#include "Cabin.h"



Cabin::Cabin(std::string _is,int _id,int _nrPeople, int _size,std::string _room, int _beds, bool _bathroomWithBath, bool _bbq, bool _surrond, bool _clean, bool _breakfast) :
	Accommodations(_is,_id,_nrPeople, _size,_room, _bathroomWithBath, _bbq, _surrond, _clean, _breakfast), bedRooms(_beds)
{


}

const int Cabin::getBedrooms() const
{
	return bedRooms;
}



void Cabin::setBedrooms(int beds)
{
	bedRooms = beds;
}


const std::string Cabin::toString() const
{
	return "Accommodation kind: " + luxuryLevel.getAccommodationKind() + "\n" +
		"Cabin Room: " + Accommodations::getRoomID() + "\n"
		+ "Beds: " + std::to_string(getBedrooms()) + "\n"
		+ Accommodations::toString();
}


