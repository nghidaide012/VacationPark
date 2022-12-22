#include <iostream>
#include <iomanip>
#include "Booking.h"
#include "VacationParcs.h"
#include <fstream>
#include <algorithm>
#include <sstream>





//user
void deleteUser(std::vector<Customer*>&);
void addCustomer(std::vector<Customer*>&);
void readCustomers(std::vector<Customer*>&);
void upgradeStaff(std::vector<Customer*>&);
void showAllCustomer(std::vector<Customer*>&);
Customer* Login(std::vector<Customer*>&);
void modifyCustomerInfo(Customer*&);
void storeCustomer(std::vector<Customer*>&);
//Accommodations
void readAccommodations(std::vector<VacationParcs*>&);
void addAccommodation(std::vector<VacationParcs*>&);
void deleteAccommodation(std::vector<VacationParcs*>&);
void modifyAccommodation(std::vector<VacationParcs*>&);
void searchAccommodations(std::vector<VacationParcs*>&);
void storeAccommodations(std::vector<VacationParcs*>&);
//Parcs
void readParcs(std::vector<VacationParcs*>&);
void deleteParcs(std::vector<VacationParcs*>&);
void showParc(std::vector<VacationParcs*>&, std::string);
void addParc(std::vector<VacationParcs*>&);
void storeParc(std::vector<VacationParcs*>&);
//vacationParcs
void readVacationParcs(std::vector<VacationParcs*>&);
void addParcsRegions(std::vector<VacationParcs*>&);
void deleteParcsRegion(std::vector<VacationParcs*>&);
void showAllParcsInWorld(std::vector<VacationParcs*>&);
void storeVacationParcs(std::vector<VacationParcs*>&);
//Booking
void readBooking(std::vector<Booking*>&, std::vector<Customer*>&, std::vector<VacationParcs*>&);
void addBooking(std::vector<Booking*>&, Customer*&, std::vector<VacationParcs*>&);
void deleteBooking(std::vector<Booking*>&);
void showAllBooking(std::vector<Booking*>&, std::vector<VacationParcs*>&);
void showCustomerBooking(std::vector<Booking*>&, Customer*&, std::vector<VacationParcs*>&);
void storeBooking(std::vector<Booking*>&);


int main()
{
	//read all data from files and connect them
	std::vector<VacationParcs*> parc_regions;
	std::vector<Customer*> customers;
	std::vector<Booking*> books;
	readCustomers(customers);
	readVacationParcs(parc_regions);
	readParcs(parc_regions);
	readAccommodations(parc_regions);
	readBooking(books, customers, parc_regions);
	int op;
	do{

		std::cout << "1.Log in\n2.Register\nChoose: ";
		std::cin >> op;
		switch (op)
		{
		case 1:
		{
			Customer* loggedInUser = Login(customers);
			if (loggedInUser->getName().empty())
			{
				std::cout << "No user with this email address." << std::endl;
				break;
			}
			else
			{
				int permission = loggedInUser->getPermission();
				std::cout << "Welcome, " << loggedInUser->getName() << "!" << std::endl;
				switch (permission)
				{
				case 3:
				{
					int option;
					std::cout << "Role: Admin" << std::endl;
					do {
						std::cout << "Menu:\n1.Show Vacation Parcs\n2.Show Accommodation(not booked)\n3.Create Vacation Parc\n4.Create Parc\n5.Create Accommodation\n6.Delete Vacation Parc\n7.Delete Parc\n8.Delete Accommodation\n9.modify Accommodation\n10.Upgrade Staff\nChoose:";
						std::cin >> option;
						switch (option) {
						case 1:
						{
							showAllParcsInWorld(parc_regions);
							break;
						}
						case 2:
						{
							std::cin.ignore();
							searchAccommodations(parc_regions);
							break;
						}
						case 3:
						{
							std::cin.ignore();
							addParcsRegions(parc_regions);
							break;
						}
						case 4:
						{
							std::cin.ignore();
							addParc(parc_regions);
							break;
						}
						case 5:
						{
							std::cin.ignore();
							addAccommodation(parc_regions);
							break;
						}
						case 6:
						{
							std::cin.ignore();
							deleteParcsRegion(parc_regions);
							break;
						}
						case 7:
						{
							std::cin.ignore();
							deleteParcs(parc_regions);
							break;
						}
						case 8:
						{
							std::cin.ignore();
							deleteAccommodation(parc_regions);
							break;
						}
						case 9:
						{
							std::cin.ignore();
							modifyAccommodation(parc_regions);
							break;
						}
						case 10:
						{
							std::cin.ignore();
							upgradeStaff(customers);
							break;
						}
						default:
						{
							break;
						}
						}
					} while (option >= 1 && option <= 10);
					break;
				}
				case 2:
				{
					int option;
					std::cout << "Role: Employee" << std::endl;
					do {
						std::cout << "Menu:\n1.Search Accommodations(not booked)\n2.Show all Booking\n3.Show all customers\n4.delete User\n5.delete Booking\n6.modify Accommodations\nChoose: ";

						std::cin >> option;
						switch (option) {
						case 1:
						{
							std::cin.ignore();
							searchAccommodations(parc_regions);
							break;
						}
						case 2:
						{
							std::cin.ignore();
							showAllBooking(books, parc_regions);
							break;
						}
						case 3:
						{
							std::cin.ignore();
							showAllCustomer(customers);
							break;
						}
						case 4:
						{	
							std::cin.ignore();
							deleteUser(customers);
							break;
						}
						case 5:
						{
							std::cin.ignore();
							deleteBooking(books);
							break;
						}
						case 6:
						{
							std::cin.ignore();
							modifyAccommodation(parc_regions);
							break;
						}
						
						default:
						{
							break;
						}
						}
					} while (option >= 1 && option <= 6);
					break;
				}
				case 1:
				{
					int option;
					std::cout << "Role: Customer" << std::endl;
					do {
						std::cout << "Menu:\n1.Search Accommodation\n2.show Booking\n3.Add Booking\n4.change information\nChoose: ";
						std::cin >> option;
						switch (option) {
						case 1:
						{
							std::cin.ignore();
							searchAccommodations(parc_regions);
							break;
						}
						case 2:
						{
							std::cin.ignore();
							showCustomerBooking(books, loggedInUser, parc_regions);
							break;
						}
						case 3:
						{
							std::cin.ignore();
							addBooking(books, loggedInUser, parc_regions);
							break;
						}
						case 4:
						{
							std::cin.ignore();
							modifyCustomerInfo(loggedInUser);
							break;
						}
						default:
						{
							break;
						}
						}
					} while (option >= 1 && option <= 4);
					break;
				}
				}
			}
			break;
		}
		case 2:
		{
			std::cout << "Register\n";
			addCustomer(customers);
			break;
		}
		default:
			break;
		}
	} while (op >= 1 && op<=2);
	storeVacationParcs(parc_regions);
	storeParc(parc_regions);
	storeAccommodations(parc_regions);
	storeCustomer(customers);
	storeBooking(books);
	return 0;
}

void storeBooking(std::vector<Booking*>& _book)
{
	std::ofstream out_file("booking.txt");
	if (!out_file.is_open()) {
		std::cerr << "Error opening file for writing." << std::endl;
		exit(1);
	}
	for (const Booking* i : _book)
	{
		for (const Accommodations* j : i->getAccommodation())
		{
			out_file << i->getCustomer().getMail() << ","
				<< j->getID() << ","
				<< i->getActivityPass() << ","
				<< i->getSportsPass() << ","
				<< i->getBicycleRent() << ","
				<< i->GetSwimmingPass() << std::endl;
		}
	}
	out_file.close();

}
void storeVacationParcs(std::vector<VacationParcs*>& _parc)
{
	std::ofstream out_file("vacationparcs.txt");
	if (!out_file.is_open()) {
		std::cerr << "Error opening file for writing." << std::endl;
		exit(1);
	}
	for (const VacationParcs* i : _parc)
	{
		out_file << i->getName() << ","
			<< i->getRegions() << std::endl;
	}
	out_file.close();

}
void storeParc(std::vector<VacationParcs*>& _parc)
{
	std::ofstream out_file("parcs.txt");
	if (!out_file.is_open()) {
		std::cerr << "Error opening file for writing." << std::endl;
		exit(1);
	}

	for (const VacationParcs* i : _parc)
	{
		for (const Parcs* j : i->getParcs())
		{
			out_file << j->getRegionID() << ","
				<< j->getName() << ","
				<< j->getAddress() << ","
				<< j->getService().getSubtropicSwimmingPool() << ","
				<< j->getService().getSport() << ","
				<< j->getService().getBowling() << ","
				<< j->getService().getBicyle() << ","
				<< j->getService().getChildren() << ","
				<< j->getService().getWaterBikes() << std::endl;
		}
	}
	out_file.close();

}
void storeAccommodations(std::vector<VacationParcs*>& _parc)
{
	std::ofstream out_file("accommodations.txt");
	if (!out_file.is_open()) {
		std::cerr << "Error opening file for writing." << std::endl;
		exit(1);
	}
	for (const VacationParcs* i : _parc)
	{
		for (const Parcs* j : i->getParcs())
		{
			for (const Accommodations* k : j->getAccommodations())
			{
				if(k->getIswhich() == "Cabin")
				{
					out_file << k->getIswhich() << ","
						<< k->getParcID() << ","
						<< k->getNrPeople() << ","
						<< k->getSize() << ","
						<< k->getRoomID() << ","
						<< k->getBedrooms() << ","
						<< k->getBathroomWithBath() << ","
						<< k->getLuxuryLevel().getBBQ() << ","
						<< k->getLuxuryLevel().getSurrondSystem() << ","
						<< k->getLuxuryLevel().getCleaning() << ","
						<< k->getLuxuryLevel().getBreakfast() << std::endl;
				}
				else if (k->getIswhich() == "Hotel")
				{
					out_file << k->getIswhich() << ","
						<< k->getParcID() << ","
						<< k->getNrPeople() << ","
						<< k->getSize() << ","
						<< k->getRoomID() << ","
						<< k->getFloor() << ","
						<< k->getBedrooms() << ","
						<< k->getChildBeds() << ","
						<< k->getBathroomWithBath() << ","
						<< k->getLuxuryLevel().getBBQ() << ","
						<< k->getLuxuryLevel().getSurrondSystem() << ","
						<< k->getLuxuryLevel().getCleaning() << ","
						<< k->getLuxuryLevel().getBreakfast() << std::endl;
				}
			}
		}
	}
	out_file.close();
}
void storeCustomer(std::vector<Customer*>& _customer)
{
	std::ofstream out_file("customers.txt");
	if (!out_file.is_open()) {
		std::cerr << "Error opening file for writing." << std::endl;
		exit(1);
	}
	for (const Customer* i : _customer) {
		out_file << i->getName() << ","
			<< i->getAddress() << ","
			<< i->getMail() << ","
			<< i->getPermission() << std::endl;
	}

	// Close the file
	out_file.close();
}
void searchAccommodations(std::vector<VacationParcs*>& _parc)
{
	showAllParcsInWorld(_parc);
	std::string region;
	int region_id;
	bool found2 = false;

	while (true) {
		std::cout << "Which Vacation Parc region do u want to check: ";
		getline(std::cin, region);

		if (region == "0") {
			break;
		}

		for (const VacationParcs* j : _parc) {

			if (j->getRegions() == region) {
				region_id = j->getID();
				found2 = true;
				break;
			}

		}

		if (found2) {
			break;
		}
		else {
			std::cout << "The Vacation Parc does not exist. Please try again." << std::endl;
		}
	}

	if (found2) {
		showParc(_parc, region);
		std::string name;
		bool found3 = false;

		while (true) {
			std::cout << "Enter the parc name: ";
			getline(std::cin, name);

			if (name == "0") {
				break;
			}

			for (const VacationParcs* j : _parc) {
				if (j->getRegions() == region)
				{
					for (const Parcs* i : j->getParcs()) {
						if (i->getName() == name) {
							found3 = true;
							break;
						}
					}
				}
			}

			if (found3) {
				break;
			}
			else {
				std::cout << "The parc does not exist. Please try again." << std::endl;
			}
		}
		if (found3)
		{
			std::cout << std::left << std::setw(20) << std::setfill(' ') << "Accommodation kind"
				<< std::left << std::setw(10) << std::setfill(' ') << "RoomID"
				<< std::left << std::setw(10) << std::setfill(' ') << "Floor"
				<< std::left << std::setw(20) << std::setfill(' ') << "Number of people"
				<< std::left << std::setw(10) << std::setfill(' ') << "Size"
				<< std::left << std::setw(10) << std::setfill(' ') << "Beds"
				<< std::left << std::setw(20) << std::setfill(' ') << "Bed for children"
				<< std::left << std::setw(20) << std::setfill(' ') << "Bathroom with bath"
				<< std::left << std::setw(10) << std::setfill(' ') << "BBQ"
				<< std::left << std::setw(20) << std::setfill(' ') << "Surround sound"
				<< std::left << std::setw(20) << std::setfill(' ') << "Cleaning service"
				<< std::left << std::setw(20) << std::setfill(' ') << "Breakfast" << std::endl;
			for (const VacationParcs* j : _parc) {
				if (j->getRegions() == region)
				{
					for (const Parcs* i : j->getParcs()) {
						if (i->getName() == name) {
							for (const Accommodations* k : i->getAccommodations())
							{
								if (!k->getBooked())
								{
									if (k->getIswhich() == "Hotel")
									{
										std::cout << std::left << std::setw(20) << std::setfill(' ') << k->getIswhich()
											<< std::left << std::setw(10) << std::setfill(' ') << k->getRoomID()
											<< std::left << std::setw(10) << std::setfill(' ') << k->getFloor()
											<< std::left << std::setw(20) << std::setfill(' ') << k->getNrPeople()
											<< std::left << std::setw(10) << std::setfill(' ') << k->getSize()
											<< std::left << std::setw(10) << std::setfill(' ') << k->getBedrooms()
											<< std::left << std::setw(20) << std::setfill(' ') << k->getChildBeds()
											<< std::left << std::setw(20) << std::setfill(' ') << k->getBathroomWithBath()
											<< std::left << std::setw(10) << std::setfill(' ') << k->getLuxuryLevel().getBBQ()
											<< std::left << std::setw(20) << std::setfill(' ') << k->getLuxuryLevel().getSurrondSystem()
											<< std::left << std::setw(20) << std::setfill(' ') << k->getLuxuryLevel().getCleaning()
											<< std::left << std::setw(20) << std::setfill(' ') << k->getLuxuryLevel().getBreakfast() << std::endl;
									}
									else if (k->getIswhich() == "Cabin")
									{
										std::cout << std::left << std::setw(20) << std::setfill(' ') << k->getIswhich()
											<< std::left << std::setw(10) << std::setfill(' ') << k->getRoomID()
											<< std::left << std::setw(10) << std::setfill(' ') << "NaN"
											<< std::left << std::setw(20) << std::setfill(' ') << k->getNrPeople()
											<< std::left << std::setw(10) << std::setfill(' ') << k->getSize()
											<< std::left << std::setw(10) << std::setfill(' ') << k->getBedrooms()
											<< std::left << std::setw(20) << std::setfill(' ') << "NaN"
											<< std::left << std::setw(20) << std::setfill(' ') << k->getBathroomWithBath()
											<< std::left << std::setw(10) << std::setfill(' ') << k->getLuxuryLevel().getBBQ()
											<< std::left << std::setw(20) << std::setfill(' ') << k->getLuxuryLevel().getSurrondSystem()
											<< std::left << std::setw(20) << std::setfill(' ') << k->getLuxuryLevel().getCleaning()
											<< std::left << std::setw(20) << std::setfill(' ') << k->getLuxuryLevel().getBreakfast() << std::endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
void showCustomerBooking(std::vector<Booking*>& _book, Customer*& _customer, std::vector<VacationParcs*>& _parc)
{
	std::cout << std::left << std::setw(30) << std::setfill(' ') << "Customer"
		<< std::left << std::setw(30) << std::setfill(' ') << "RoomID"
		<< std::left << std::setw(30) << std::setfill(' ') << "Parc"
		<< std::left << std::setw(30) << std::setfill(' ') << "Region" << std::endl;
	for (const Booking* i : _book)
	{
		if (i->getCustomer().getMail() == _customer->getMail())
		{
			for (const VacationParcs* j : _parc)
			{
				for (const Parcs* k : j->getParcs())
				{
					for (const Accommodations* l : i->getAccommodation())
					{
						if (l->getParcID() == k->getID())
						{
							if (k->getRegionID() == j->getID())
							{
								std::cout << std::left << std::setw(30) << std::setfill(' ') << i->getCustomer().getMail()
									<< std::left << std::setw(30) << std::setfill(' ') << l->getRoomID()
									<< std::left << std::setw(30) << std::setfill(' ') << k->getName()
									<< std::left << std::setw(30) << std::setfill(' ') << j->getName() << std::endl;
							}
						}
					}
				}
			}
		}
	}
}
void showAllBooking(std::vector<Booking*>& _book, std::vector<VacationParcs*>& _parc)
{
	std::cout << std::left << std::setw(30) << std::setfill(' ') << "Customer"
		<< std::left << std::setw(30) << std::setfill(' ') << "RoomID"
		<< std::left << std::setw(30) << std::setfill(' ') << "Parc"
		<< std::left << std::setw(30) << std::setfill(' ') << "Region" << std::endl;
	for (const Booking* i : _book)
	{
		for (const VacationParcs* j : _parc)
		{
			for (const Parcs* k : j->getParcs())
			{
				for(const Accommodations* l : i->getAccommodation())
				{
					if (l->getParcID() == k->getID())
					{
						if (k->getRegionID() == j->getID())
						{
							std::cout << std::left << std::setw(30) << std::setfill(' ') << i->getCustomer().getMail()
								<< std::left << std::setw(30) << std::setfill(' ') << l->getRoomID()
								<< std::left << std::setw(30) << std::setfill(' ') << k->getName()
								<< std::left << std::setw(30) << std::setfill(' ') << j->getName() << std::endl;
						}
					}
				}
			}
		}
	}
}
void deleteBooking(std::vector<Booking*>& _book)
{
	std::string email;
	bool found =false;

	while (true) {
		std::cout << "Enter email of the customer that u want to delete Booking data: ";
		std::cin >> email;

		for (const Booking* i : _book) {
			
			if (i->getCustomer().getMail() == email) {
				found = true;
				break;
			}

		}

		if (found) {
			break;
		}
		else {
			std::cout << "This Customer is not exist in Booking data" << std::endl;
		}
	}
	if (found)
	{
		for (Booking* i : _book)
		{
			if (i->getCustomer().getMail() == email) {
				delete i;
				_book.erase(std::remove(_book.begin(), _book.end(), i));
				break;
			}
		}
	}
	
}
void addBooking(std::vector<Booking*>& _book, Customer*& _customer, std::vector<VacationParcs*>& _parc)
{
	std::string region;
	int region_id;
	bool found2 = false;

	while (true) {
		std::cout << "Which Vacation Parc region do u want to book: ";
		getline(std::cin, region);

		if (region == "0") {
			break;
		}

		for (const VacationParcs* j : _parc) {

			if (j->getRegions() == region) {
				region_id = j->getID();
				found2 = true;
				break;
			}

		}

		if (found2) {
			break;
		}
		else {
			std::cout << "The Vacation Parc does not exist. Please try again." << std::endl;
		}
	}
	if (found2) {
		std::string name;
		bool found3 = false;

		while (true) {
			std::cout << "Enter the parc name: ";
			getline(std::cin, name);

			if (name == "0") {
				break;
			}

			for (const VacationParcs* j : _parc) {
				if(j->getRegions() == region)
				{
					for (const Parcs* i : j->getParcs()) {
						if (i->getName() == name) {
							found3 = true;
							break;
						}
					}
				}
			}

			if (found3) {
				break;
			}
			else {
				std::cout << "The parc does not exist. Please try again." << std::endl;
			}
		}
		if(found3) {
			std::string room;
			bool found = false;

			while (true) {
				std::cout << "Enter the room ID: ";
				std::cin >> room;

				for (const VacationParcs* i : _parc) {
					if (i->getRegions() == region)
					{
						for (const Parcs* j : i->getParcs())
						{	
							if(j->getName() == name)
							{
								for (const Accommodations* k : j->getAccommodations())
								{
									if (k->getRoomID() == room && !k->getBooked()) {
										found = true;
										break;
									}
								}
							}
						}
					}
				}

				if (found) {
					break;
				}
				else {

					std::cout << "This room ID doesn't exist or already booked!!" << std::endl;
				}
			}
			if (found) {
				if (_customer->getBooked())
				{
					for (Booking* i : _book)
					{
						if (i->getCustomer().getMail() == _customer->getMail())
						{
							for (VacationParcs* j : _parc) {
								for (Parcs* k : j->getParcs())
								{
									for (Accommodations* l : k->getAccommodations())
									{
										if (l->getRoomID() == room) {
											i->addAccommodation(l);
											break;
										}
									}
								}
							}
						}
					}
				}
				else
				{
					int bbq, surrond, clean, breakfast;
					std::cout << "Service(enter any number for YES and 0 for NO): " << std::endl;
					std::cout << "BBQ: ";
					std::cin >> bbq;
					std::cout << "Surrond System: ";
					std::cin >> surrond;
					std::cout << "Cleaning service: ";
					std::cin >> clean;
					std::cout << "Breakfast service: ";
					std::cin >> breakfast;
					for (VacationParcs* j : _parc) {
						for (Parcs* k : j->getParcs())
						{
							for (Accommodations* l : k->getAccommodations())
							{
								if (l->getRoomID() == room) {
									_book.push_back(new Booking(_customer, l, (bbq != 0), (surrond != 0), (clean != 0), (breakfast != 0)));
									break;
								}
							}
						}
					}
				}
			}
		}
	}
}
void readBooking(std::vector<Booking*>& _book, std::vector<Customer*>& _customer, std::vector<VacationParcs*>& _parc)
{
	std::ifstream file("booking.txt");
	if (file.fail()) {
		std::cerr << "Error: Could not open file" << std::endl;
		exit(1);
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string cus_mail, acco_id, activity, sport, bicycle, swim;
		std::getline(ss, cus_mail, ',');
		std::getline(ss, acco_id, ',');
		std::getline(ss, activity, ',');
		std::getline(ss, sport, ',');
		std::getline(ss, bicycle, ',');
		std::getline(ss, swim);

		for (Customer* i : _customer)
		{
			if (i->getMail() == cus_mail) {
				for (VacationParcs* j : _parc)
				{
					for (Parcs* k : j->getParcs())
					{
						for (Accommodations* l : k->getAccommodations())
						{
							if (l->getID() == std::stoi(acco_id))
							{
								if (!i->getBooked())
								{
									_book.push_back(new Booking(i, l, (std::stoi(activity) != 0), (std::stoi(sport) != 0),
										(std::stoi(bicycle) != 0), (std::stoi(swim) != 0)));
									break;
								}
								else
								{
									for (Booking* b : _book)
									{
										if (b->getCustomer().getMail() == cus_mail)
										{
											b->addAccommodation(l);
											break;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	file.close();

}
void addParc(std::vector<VacationParcs*>& _parc)
{

	std::string region;
	int region_id;
	bool found = false;

	while (true) {
		std::cout << "Which Vacation Parc region does the new parc belong to: ";
		getline(std::cin, region);

		if (region == "0") {
			break;
		}

		for (const VacationParcs* j : _parc) {

			if (j->getRegions() == region) {
				 region_id=j->getID()  ;
				found = true;
				break;
			}

		}

		if (found) {
			break;
		}
		else {
			std::cout << "The Vacation Parc does not exist. Please try again." << std::endl;
		}
	}
	if (found)
	{
		std::cout << region_id << std::endl;
		std::string name, address;
		int swim, sport, bowling, bicycle, children, water;
		while (true) {
			std::cout << "Enter the parc name: ";
			getline(std::cin, name);

			bool found2 = false;
			for (const VacationParcs* i : _parc) {
				if (i->getID() == region_id)
				{
					for (const Parcs* j : i->getParcs())
					{

						if (j->getName() == name) {
							found2 = true;
							break;
						}
					}
				}
			}

			if (found2) {
				std::cout << "This Parc already exist!!" << std::endl;
			}
			else {
				break;
			}
		}
		while (true) {
			std::cout << "Enter the address for the parc: ";
			getline(std::cin, address);

			bool found2 = false;
			for (const VacationParcs* i : _parc) {
				if (i->getID() == region_id)
				{
					for (const Parcs* j : i->getParcs())
					{
						if (j->getAddress() == address) {
							found2 = true;
							break;
						}
					}
				}
			}

			if (found2) {
				std::cout << "This address already exist!" << std::endl;
			}
			else {
				break;
			}
		}
		std::cout << "Parc Service (enter any number for YES and 0 for NO): " << std::endl;
		std::cout << "Subtropic SwimmingPool: ";
		std::cin >> swim;
		std::cout << "Sports infrastructured: ";
		std::cin >> sport;
		std::cout << "Bowling Alley: ";
		std::cin >> bowling;
		std::cout << "Bicyle Rent: ";
		std::cin >> bicycle;
		std::cout << "Children Paradise: ";
		std::cin >> children;
		std::cout << "Water Bikes: ";
		std::cin >> water;
		
		for (VacationParcs* i : _parc) {
			if (i->getID() == region_id)
			{
				i->addParcs(new Parcs(i->getID(), name, address, ParcService((swim != 0), (sport != 0), (bowling != 0),
					(bicycle != 0), (children != 0), (water != 0))));
			}
		}
	}
}

void showParc(std::vector<VacationParcs*>& _parc, std::string region)
{
	std::cout << std::left << std::setfill(' ') << std::setw(10) << "Name" << std::setw(30) << "Address" << std::setw(30) << "Number of Accommodation"
		<< std::setw(30) << "Subtropic SwimmingPool" << std::setw(30) << "Sports infrastructured" << std::setw(20) << "Bowling Alley"
		<< std::setw(20) << "Bicycle Rent" << std::setw(20) << "Children Paradise" << std::setw(20) << "Water Bikes" << std::endl;
	for (const VacationParcs* i : _parc)
	{
		if (i->getRegions() == region)
		{
			for (const Parcs* j : i->getParcs())
			{
				std::cout << std::left << std::setfill(' ') << std::setw(10) << j->getName() << std::setw(30) << j->getAddress() << std::setw(30) << j->getAccommodations().size()
					<< std::setw(30) << j->getService().getSubtropicSwimmingPool() << std::setw(30) << j->getService().getSport() << std::setw(20) << j->getService().getBowling()
					<< std::setw(20) << j->getService().getBicyle() << std::setw(20) << j->getService().getChildren() << std::setw(20) << j->getService().getWaterBikes() << std::endl;
			}
		}
	}
}
void modifyAccommodation(std::vector<VacationParcs*>& _parc)
{

	std::string region;
	int region_id = 0;
	bool found3 = false;

	while (true) {
		std::cout << "Which Vacation Parc region is the accommodation belong to: ";
		getline(std::cin, region);

		if (region == "0") {
			break;
		}

		for (const VacationParcs* j : _parc) {

			if (j->getRegions() == region) {
				region_id = j->getID();
				found3 = true;
				break;
			}

		}

		if (found3) {
			break;
		}
		else {
			std::cout << "The Vacation Parc does not exist. Please try again." << std::endl;
		}
	}
	if (found3) {
		int id;
		std::string name;
		bool found = false;

		while (true) {
			std::cout << "which Parc does this accommodation belong to: ";
			getline(std::cin, name);


			if (name == "0") {
				break;
			}

			for (const VacationParcs* j : _parc) {
				if (region_id == j->getID()) {
					for (const Parcs* i : j->getParcs()) {
						if (i->getName() == name) {
							id = i->getID();
							found = true;
							break;
						}
					}
				}
			}

			if (found) {
				break;
			}
			else {
				std::cout << "The parc does not exist. Please try again." << std::endl;
			}
		}
		if (found) {
			std::string room,kind;
			bool found2 = false;

			while (true) {
				std::cout << "Enter the room id: ";
				getline(std::cin, room);

				if (room == "0") {
					break;
				}

				for (const VacationParcs* i : _parc) {
					if (i->getID() == region_id)
					{
						for (const Parcs* j : i->getParcs())
						{
							if (j->getID() == id)
							{
								for (const Accommodations* k : j->getAccommodations())
								{
									if (k->getRoomID() == room) {
										kind = k->getIswhich();
										found2 = true;
										break;
									}
								}
							}
						}
					}
				}

				if (found2) {
					break;
				}
				else {
					std::cout << "The room does not exist. Please try again." << std::endl;
				}
			}
			if (found2)
			{
				int num_people, size, beds;
				int bath, bbq, surrond, clean, breakfast;
				std::cout << "how many adult bed in the room: ";
				std::cin >> beds;
				std::cout << "how large is the room(m2): ";
				std::cin >> size;
				std::cout << "how many people can be in this room: ";
				std::cin >> num_people;
				std::cout << "Service(enter any number for YES and 0 for NO: " << std::endl;
				std::cout << "Bathroom with bath: ";
				std::cin >> bath;
				std::cout << "BBQ: ";
				std::cin >> bbq;
				std::cout << "Surrond System: ";
				std::cin >> surrond;
				std::cout << "Cleaning service: ";
				std::cin >> clean;
				std::cout << "Breakfast service: ";
				std::cin >> breakfast;
				if (kind == "Hotel")
				{
					int floor, child;
					std::cout << "which floor is this room in: ";
					std::cin >> floor;
					std::cout << "how many children bed in the room: ";
					std::cin >> child;
					for (VacationParcs* i : _parc) {
						for (Parcs* j : i->getParcs())
						{
							for (Accommodations* k : j->getAccommodations())
							{
								if (k->getRoomID() == room) {
									k->setLuxuryLevel(kind, (bbq != 0), (surrond != 0), (clean != 0), (breakfast != 0));
									k->setFloor(floor);
									k->setChildBeds(child);
									k->setBedrooms(beds);
									k->setSize(size);
									k->setNrPeople(num_people);
									break;
								}
							}
						}
					}

				}
				else if (kind == "Cabin")
				{
					for (VacationParcs* i : _parc) {
						for (Parcs* j : i->getParcs())
						{
							for (Accommodations* k : j->getAccommodations())
							{
								if (k->getRoomID() == room) {
									k->setLuxuryLevel(kind, (bbq != 0), (surrond != 0), (clean != 0), (breakfast != 0));
									k->setBedrooms(beds);
									k->setSize(size);
									k->setNrPeople(num_people);
									break;
								}
							}
						}
					}
				}
			}
		}
	}


}
void modifyCustomerInfo(Customer*& customer) {
	std::string name;
	std::string address;
	std::string mail;

	std::cout << "Enter the new name: ";

	getline(std::cin, name);
	customer->setName(name);
	std::cout << "Enter the new address: ";
	getline(std::cin, address);
	customer->setAddress(address);
	std::cout << "Enter the new email: ";
	std::cin >> mail;
	customer->setMail(mail);


}
Customer* Login(std::vector<Customer*>& _customer)
{
	std::string email;
	std::cout << "Enter your email: ";
	std::cin >> email;
	for (Customer* i : _customer)
	{
		if (i->getMail() == email)
		{
			return i;
		}
	}
	return new Customer();
}
void deleteParcsRegion(std::vector<VacationParcs*>& _parc)
{
	std::string region;
	bool found = false;

	while (true) {
		std::cout << "Enter the Vacation Parc region: ";
		getline(std::cin, region);

		if (region == "0") {
			break;
		}

		for (const VacationParcs* j : _parc) {

				if (j->getRegions() == region) {
					found = true;
					break;
				}
			
		}

		if (found) {
			break;
		}
		else {
			std::cout << "The Vacation Parc does not exist. Please try again." << std::endl;
		}
	}
	if (found)
	{
		for (VacationParcs*& i : _parc) {
				if (i->getRegions() == region) {
					delete i;
					_parc.erase(std::remove(_parc.begin(), _parc.end(), i));
				}
		}
	}

}

void deleteAccommodation(std::vector<VacationParcs*>& _parc)
{
	std::string region;
	int region_id = 0;
	bool found3 = false;

	while (true) {
		std::cout << "Which Vacation Parc region is the accommodation belong to: ";
		getline(std::cin, region);

		if (region == "0") {
			break;
		}

		for (const VacationParcs* j : _parc) {

			if (j->getRegions() == region) {
				region_id = j->getID();
				found3 = true;
				break;
			}

		}

		if (found3) {
			break;
		}
		else {
			std::cout << "The Vacation Parc does not exist. Please try again." << std::endl;
		}
	}
	if(found3) {
		int id;
		std::string name;
		bool found = false;

		while (true) {
			std::cout << "which Parc does this accommodation belong to: ";
			getline(std::cin, name);


			if (name == "0") {
				break;
			}

			for (const VacationParcs* j : _parc) {
				if (region_id == j->getID()) {
					for (const Parcs* i : j->getParcs()) {
						if (i->getName() == name) {
							id = i->getID();
							found = true;
							break;
						}
					}
				}
			}

			if (found) {
				break;
			}
			else {
				std::cout << "The parc does not exist. Please try again." << std::endl;
			}
		}
		if(found) {
			std::string room;
			bool found2 = false;

			while (true) {
				std::cout << "Enter the room id: ";
				getline(std::cin, room);

				if (room == "0") {
					break;
				}

				for (const VacationParcs* i : _parc) {
					if(i->getID() == region_id)
					{
						for (const Parcs* j : i->getParcs())
						{
							if(j->getID() == id)
							{
								for (const Accommodations* k : j->getAccommodations())
								{
									if (k->getRoomID() == room) {
										found2 = true;
										break;
									}
								}
							}
						}
					}
				}

				if (found2) {
					break;
				}
				else {
					std::cout << "The room does not exist. Please try again." << std::endl;
				}
			}
			if (found2)
			{
				for (VacationParcs* i : _parc) {
					if (i->getID() == region_id)

					{
						for (Parcs* j : i->getParcs())
						{
							if (j->getID() == id)
							{
								for (Accommodations* k : j->getAccommodations())
								{
									if (k->getRoomID() == room) {
										j->deleteAccommodation(k->getID());
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
void addAccommodation(std::vector<VacationParcs*>& _parc)
{

	std::string region;
	int region_id = 0;
	bool found3 = false;

	while (true) {
		std::cout << "Which Vacation Parc region is the accommodation belong to: ";
		getline(std::cin, region);

		if (region == "0") {
			break;
		}

		for (const VacationParcs* j : _parc) {

			if (j->getRegions() == region) {
				region_id = j->getID();
				found3 = true;
				break;
			}

		}

		if (found3) {
			break;
		}
		else {
			std::cout << "The Vacation Parc does not exist. Please try again." << std::endl;
		}
	}
	if (found3)
	{
		int id;
		std::string name;
		bool found = false;

		while (true) {
			std::cout << "which Parc does this accommodation belong to: ";
			getline(std::cin, name);


			if (name == "0") {
				break;
			}

			for (const VacationParcs* j : _parc) {
				if(region_id == j->getID()) {
					for (const Parcs* i : j->getParcs()) {
						if (i->getName() == name) {
							id = i->getID();
							found = true;
							break;
						}
					}
				}
			}

			if (found) {
				break;
			}
			else {
				std::cout << "The parc does not exist. Please try again." << std::endl;
			}
		}
		if (found)
		{
			int options_acco;
			std::string kind, room;
			int num_people, size, beds;
			int bath, bbq, surrond, clean, breakfast;
			do
			{

				std::cout << "What kind is this accommodation:\n1.Hotel\n2.Cabin\nChoose: ";
				std::cin >> options_acco;
				switch (options_acco)
				{
				case 1:
					kind = "Hotel";
					break;
				case 2:
					kind = "Cabin";
					break;
				default:
					std::cout << "invalid option.Please choose again." << std::endl;
					break;
				}
			} while (options_acco < 1 || options_acco>2);
			std::cin.ignore();
			while (true) {
				std::cout << "Enter the room ID: ";
				getline(std::cin, room);

				bool found2 = false;
				for (const VacationParcs* i : _parc) {
					for (const Parcs* j : i->getParcs())
					{
						if (j->getID() == id)
						{
							for (const Accommodations* k : j->getAccommodations())
							{
								if (k->getRoomID() == room) {
									found2 = true;
									break;
								}
							}
						}
					}
				}

				if (found2) {
					std::cout << "This room ID already exist in this parc" << std::endl;
				}
				else {
					break;
				}
			}
			std::cout << "how many adult bed in the room: ";
			std::cin >> beds;
			std::cout << "how large is the room(m2): ";
			std::cin >> size;
			std::cout << "how many people can be in this room: ";
			std::cin >> num_people;
			std::cout << "Service(enter any number for YES and 0 for NO: " << std::endl;
			std::cout << "Bathroom with bath: ";
			std::cin >> bath;
			std::cout << "BBQ: ";
			std::cin >> bbq;
			std::cout << "Surrond System: ";
			std::cin >> surrond;
			std::cout << "Cleaning service: ";
			std::cin >> clean;
			std::cout << "Breakfast service: ";
			std::cin >> breakfast;
			if (kind == "Hotel")
			{
				int floor, child;
				std::cout << "which floor is this room in: ";
				std::cin >> floor;
				std::cout << "how many children bed in the room: ";
				std::cin >> child;
				for (VacationParcs* i : _parc)
				{
					for (Parcs* j : i->getParcs())
					{
						if (j->getID() == id)
						{
							j->addAccommodations(new HotelRoom(kind, id, num_people, size, room, floor, beds, child, (bath != 0), (bbq != 0), (surrond != 0), (clean != 0), (breakfast != 0)));
						}
					}
				}
			}
			else if (kind == "Cabin")
			{
				for (VacationParcs* i : _parc)
				{
					for (Parcs* j : i->getParcs())
					{
						if (j->getID() == id)
						{
							j->addAccommodations(new Cabin(kind, id, num_people, size, room, beds, (bath != 0), (bbq != 0), (surrond != 0), (clean != 0), (breakfast != 0)));
						}
					}
				}
			}

		}
	}
}
void deleteParcs(std::vector<VacationParcs*>& _parc)
{
	std::string region;
	int region_id;
	bool found = false;

	while (true) {
		std::cout << "Which Vacation Parc region does the parc belong to: ";
		getline(std::cin, region);

		if (region == "0") {
			break;
		}

		for (const VacationParcs* j : _parc) {

			if (j->getRegions() == region) {
				region_id = j->getID();
				found = true;
				break;
			}

		}

		if (found) {
			break;
		}
		else {
			std::cout << "The Vacation Parc does not exist. Please try again." << std::endl;
		}
	}
	if (found) {
		std::string name;
		bool found2 = false;

		while (true) {
			std::cout << "Enter the parc name: ";
			getline(std::cin, name);

			if (name == "0") {
				break;
			}

			for (const VacationParcs* j : _parc) {
				if (j->getID() == region_id)
				{
					for (const Parcs* i : j->getParcs()) {
						if (i->getName() == name) {
							found2 = true;
							break;
						}
					}
				}
			}

			if (found2) {
				break;
			}
			else {
				std::cout << "The parc does not exist. Please try again." << std::endl;
			}
		}
		if (found2)
		{
			for (VacationParcs*& i : _parc) {
				for (Parcs* j : i->getParcs()) {
					if (j->getName() == name) {
						i->deleteParc(j->getID());
					}
				}
			}
		}
	}
}

void deleteUser(std::vector<Customer*>& _customer)
{
	std::string mail;
	bool found = false;

	while (true) {
		std::cout << "Enter the user's email address: ";
		std::cin >> mail;

		if (mail == "0") {
			break;
		}

		for (const Customer* i : _customer) {
			if (i->getMail() == mail) {
				found = true;
				break;
			}
		}

		if (found) {
			break;
		}
		else {
			std::cout << "The user does not exist. Please try again." << std::endl;
		}
	}
	if (found)
	{
		for (Customer* i : _customer)
		{
			if (i->getMail() == mail)
			{
				if (i->getPermission() == 3)
				{
					std::cout << "This user role is too big to delete" << std::endl;
				}
				else
				{
					delete i;
					_customer.erase(std::remove(_customer.begin(), _customer.end(), i));
				}
			}
		}
	}

}

void addParcsRegions(std::vector<VacationParcs*>& _parc)
{
	std::string region;

	while (true) {
		std::cout << "Enter the region of vacation parc: ";
		getline(std::cin, region);

		bool found = false;
		for (const VacationParcs*i : _parc) {
			if (i->getRegions() == region) {
				found = true;
				break;
			}
		}

		if (found) {
			std::cout << "This Vacation Parc already exists in this region" << std::endl;
		}
		else {
			break;
		}
	}
	std::cout << "Enter the name: ";
	std::string name;
	getline(std::cin, name);
	_parc.push_back(new VacationParcs(name, region));

}
void readAccommodations(std::vector<VacationParcs*>& _parc)
{
	std::ifstream file("accommodations.txt");
	if (file.fail()) {
		std::cerr << "Error: Could not open file" << std::endl;
		exit(1);
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string kind;
		std::getline(ss, kind, ',');
		if (kind == "Hotel")
		{
			std::string parc_id, num_people, size, room, floor, beds, childbed, bath, bbq, surrond, clean, breakfast;
			std::getline(ss, parc_id, ',');
			std::getline(ss, num_people, ',');
			std::getline(ss, size, ',');
			std::getline(ss, room, ',');
			std::getline(ss, floor, ',');
			std::getline(ss, beds, ',');
			std::getline(ss, childbed, ',');
			std::getline(ss, bath, ',');
			std::getline(ss, bbq, ',');
			std::getline(ss, surrond, ',');
			std::getline(ss, clean, ',');
			std::getline(ss, breakfast);
			for (VacationParcs* i : _parc) {
				for (Parcs* j : i->getParcs()) {
					if (j->getID() == std::stoi(parc_id))
					{
						j->addAccommodations(new HotelRoom(kind, std::stoi(parc_id), std::stoi(num_people), std::stoi(size), room, std::stoi(floor), std::stoi(beds), std::stoi(childbed),
							(std::stoi(bath) != 0), (std::stoi(bbq) != 0), (std::stoi(surrond) != 0), (std::stoi(clean) != 0), (std::stoi(breakfast) != 0)));
					}
					}
				}
		}
		else if (kind == "Cabin")
		{
			std::string parc_id, num_people, size, room, beds, bath, bbq, surrond, clean, breakfast;
			std::getline(ss, parc_id, ',');
			std::getline(ss, num_people, ',');
			std::getline(ss, size, ',');
			std::getline(ss, room, ',');
			std::getline(ss, beds, ',');
			std::getline(ss, bath, ',');
			std::getline(ss, bbq, ',');
			std::getline(ss, surrond, ',');
			std::getline(ss, clean, ',');
			std::getline(ss, breakfast);
			for (VacationParcs* i : _parc) {
				for (Parcs* j : i->getParcs()) {
					if (j->getID() == std::stoi(parc_id))
					{
						j->addAccommodations(new Cabin(kind, std::stoi(parc_id), std::stoi(num_people), std::stoi(size), room,
							std::stoi(beds), (std::stoi(bath) != 0),(std::stoi(bbq) != 0), (std::stoi(surrond) != 0), (std::stoi(clean) != 0), (std::stoi(breakfast) != 0)));
					}
				}
			}
					}
	}
	file.close();

}

void readParcs(std::vector<VacationParcs*>& _parc)
{
	std::ifstream file("parcs.txt");
	if (file.fail()) {
		std::cerr << "Error: Could not open file" << std::endl;
		exit(1);
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string region_id, name, address, swim, sport, bowling, bicycle, children, water;
		std::getline(ss, region_id, ',');
		std::getline(ss, name, ',');
		std::getline(ss, address, ',');
		std::getline(ss, swim, ',');
		std::getline(ss, sport, ',');
		std::getline(ss, bowling, ',');
		std::getline(ss, bicycle, ',');
		std::getline(ss, children, ',');
		std::getline(ss, water);
		for (VacationParcs* i : _parc) {
			if (i->getID() == std::stoi(region_id))
			{
				i->addParcs(new Parcs(std::stoi(region_id), name, address, ParcService((std::stoi(swim) != 0), (std::stoi(sport) != 0),
					(std::stoi(bowling) != 0), (std::stoi(bicycle) != 0), (std::stoi(children) != 0), (std::stoi(water) != 0))));
			}
			}
		}
	file.close();

}

void readVacationParcs(std::vector<VacationParcs*>& _parc)
{
	std::ifstream file("vacationparcs.txt");
	if (file.fail()) {
		std::cerr << "Error: Could not open file" << std::endl;
		exit(1);
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string name, region;
		std::getline(ss, name, ',');
		std::getline(ss, region, ',');
		_parc.push_back(new VacationParcs(name, region));
	}
	file.close();
}

void readCustomers(std::vector<Customer*>& _customer)
{
	std::ifstream file("customers.txt");
	if (file.fail()) {
		std::cerr << "Error: Could not open file"<< std::endl;
		exit(1);
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string name, address, email, permission;
		std::getline(ss, name, ',');
		std::getline(ss, address, ',');
		std::getline(ss, email, ',');
		std::getline(ss, permission);
		_customer.push_back(new Customer(name, address, email, std::stoi(permission)));
	}
	file.close();
}



void showAllParcsInWorld(std::vector<VacationParcs*>& _parc)
{
	std::cout << std::setw(20) << std::left << "Name"
		<< std::setw(30) << std::left << "Region"
		<< std::setw(30) << std::left << "Number of parcs" << std::endl;

	for (const VacationParcs* i : _parc) {
			std::cout << std::setw(20) << std::left << i->getName()
			<< std::setw(30) << std::left << i->getRegions()
			<< std::setw(10) << std::left << i->getParcs().size() << std::endl;
	}
}

void showAllCustomer(std::vector<Customer*>& _customer)
{
	std::cout << std::setw(35) << std::left << "Name"
		<< std::setw(30) << std::left << "Address"
		<< std::setw(30) << std::left << "Email"
		<< std::setw(10) << std::left << "Permission" << std::endl;

	for (const Customer* i : _customer) {

		std::cout << std::setw(35) << std::left << i->getName()
			<< std::setw(30) << std::left << i->getAddress()
			<< std::setw(30) << std::left << i->getMail()
			<< std::setw(10) << std::left << i->getPermission() << std::endl;
	}
}

void addCustomer(std::vector<Customer*>&  _customer)
{
	std::cout << "whats your name: ";
	std::cin.ignore();
	std::string name;
	getline(std::cin, name);
	std::cout << "Enter your address: ";
	std::string address;
	getline(std::cin, address);

	std::string mail;
	while (true) {
		std::cout << "Enter the user's email address: ";
		std::cin >> mail;

		bool found = false;
		for (const Customer* i : _customer) {
			if (i->getMail() == mail) {
				found = true;
				break;
			}
		}

		if (found) {
			std::cout << "The user already exists. Please try again." << std::endl;
		}
		else {
			break;
		}
	}


	_customer.push_back(new Customer(name, address, mail, 1));
	
}

void upgradeStaff(std::vector<Customer*>& _customer)
{
	std::string mail;
	bool found = false;

	while (true) {
		std::cout << "Enter the user's email address: ";
		std::cin >> mail;

		if (mail == "0") {
			break;
		}

		for (const Customer* i : _customer) {
			if (i->getMail() == mail) {
				found = true;
				break;
			}
		}

		if (found) {
			break;
		}
		else {
			std::cout << "The user does not exist. Please try again." << std::endl;
		}
	}
	if (found)
	{
		std::cout << "What role you want the user to become: \n1. Stay customer\n2.Employee\n3.Admin\nChoose: ";
		int role;
		std::cin >> role;
		while (role > 3 && role <= 0)
		{
			std::cout << "You only have 3 options, please choose again.\n1. Stay customer\n2.Employee\n3.Admin\nChoose:";
			std::cin >> role;
		}
		for (Customer* i : _customer)
		{
			if (i->getMail() == mail)
			{
				i->setPermission(role);
			}
		}
	}
}