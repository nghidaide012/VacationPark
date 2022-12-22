#include "VacationParcs.h"

int VacationParcs::current_id = 1;


VacationParcs::VacationParcs(std::string _name, std::string _region):
	name(_name), regions(_region){
	id = current_id++;
}

const int VacationParcs::getID() const
{
	return id;
}
const std::string VacationParcs::getName() const
{
	return name;
}
const std::string VacationParcs::getRegions() const
{
	return regions;
}
const std::vector<Parcs*> VacationParcs::getParcs() const
{
	return parcs;
}


void VacationParcs::deleteParc(int _id)
{
	for (Parcs* i : parcs)
	{
		if (i->getID() == _id)
		{
			delete i;
			parcs.erase(std::remove(parcs.begin(), parcs.end(), i));
		}
	}
}
void VacationParcs::setName(std::string _name)
{
	name = _name;
}

void VacationParcs::setRegion(std::string _region)
{
	regions = _region;
}

void VacationParcs::addParcs(Parcs* _parc)
{
	parcs.push_back(_parc);
}

const std::string VacationParcs::toString() const
{
	return getName() + "\n" + "Region: " + getRegions() + "\n"
		+ "Number of Parcs: " + std::to_string(getParcs().size()) + "\n";
}
