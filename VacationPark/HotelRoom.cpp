#include "HotelRoom.h"



HotelRoom::HotelRoom(std::string _is,int _id,int _nrPeople, int _size, std::string _room, int _floor, int _beds, int _child, bool _bathroomWithBath, bool _bbq, bool _surrond, bool _clean, bool _breakfast) :
	Accommodations(_is, _id, _nrPeople, _size, _room, _bathroomWithBath, _bbq, _surrond, _clean, _breakfast), bedRooms(_beds), childBeds(_child), floor(_floor)
{


}
const int HotelRoom::getFloor() const
{
	return floor;
}
const int HotelRoom::getBedrooms() const
{
	return bedRooms;
}
const int HotelRoom::getChildBeds() const
{
	return childBeds;
}

void HotelRoom::setFloor(int _floor)
{
	floor = _floor;
}
void HotelRoom::setBedrooms(int beds)
{
	bedRooms = beds;
}
void HotelRoom::setChildBeds(int childs)
{
	childBeds = childs;
}


const std::string HotelRoom::toString() const
{
	return "Accommodation kind: " + luxuryLevel.getAccommodationKind() + "\n" +
		"Hotel room: " + Accommodations::getRoomID() + ", Floor: " + std::to_string(getFloor()) + "\n"
		+ "Adult beds: " + std::to_string(getBedrooms()) + "\n"
		+ "Children Beds: " + std::to_string(getChildBeds()) + "\n"
		+ Accommodations::toString();
}