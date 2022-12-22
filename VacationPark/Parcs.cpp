#include "Parcs.h"

int Parcs::current_id = 1;
Parcs::Parcs(int _id,std::string _name, std::string _address, ParcService _service):
	name(_name), address(_address), Parc_region_id(_id), services(_service) {
	id = current_id++;
	
}

const int Parcs::getRegionID() const
{
	return Parc_region_id;
}
const int Parcs::getID() const
{
	return id;
}
const std::string Parcs::getName() const
{
	return name;
}
const std::string Parcs::getAddress() const
{
	return address;
}
const ParcService Parcs::getService() const
{
	return services;
}

const std::vector<Accommodations*> Parcs::getAccommodations() const
{
	return accommodations;
}

void Parcs::deleteAccommodation(int _id)
{
	for (Accommodations* i : accommodations)
	{
		if (i->getID() == _id)
		{
			delete i;
			accommodations.erase(std::remove(accommodations.begin(), accommodations.end(), i));
		}
	}
}


void Parcs::setRegionID(int _id)
{
	Parc_region_id = _id;
}

void Parcs::setName(std::string _name)
{
	name = _name;
}
void Parcs::setAddress(std::string _address)
{
	address = _address;
}

void Parcs::setService(bool _swim, bool _sport, bool _bowling, bool _bicycle, bool _children, bool _water)
{
	services = ParcService(_swim, _sport, _bowling, _bicycle, _children, _water);
}

void Parcs::addAccommodations(Accommodations* _accommodation)
{
	accommodations.push_back(_accommodation);
}
const std::string Parcs::toString() const
{
	std::string str;
	str = "Parc: " + getName() + ", Location: " + getAddress() + "\n";
	str += "Number of Accommodations: " +  std::to_string(getAccommodations().size()) + "\n";
	str += "Services: \n" + getService().toString() + "\n";
	return str;
}