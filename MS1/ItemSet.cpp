#include "ItemSet.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

namespace sict {

	//initialize the static member; 
	char Utilities::delimiter{ ' ' };
	unsigned int Utilities::width{ 0u };

	const std::string& ItemSet::getName() const {
		return this->name;
	}

	const unsigned int ItemSet::getSerialNumber() const {
		return this->serialNumber;
	}
	const unsigned int ItemSet::getQuantity() const {
		return this->quantity;

	}

	ItemSet& ItemSet::operator--() {

		//reduces the number of items in stock by one
		--quantity;
		//increases the serial number by one.
		++serialNumber;

		return *this;
	}

	void ItemSet::display(ostream& os, bool full) const {
		if (!full)
		{
			//If the Boolean is false the data consists of the name of the items in the set and the next serial number to be assigned.
			os << this->name << " " << this->serialNumber << endl;

		}
		else {
			//If the Boolean is true, the data consists of the name, serial number quantity in stock 
			//and the description of the items in the set (as shown above).
			os << left << setw(utilities.getFieldWidth()) << this->name << " " << right <<
				"[" << setw(5) << setfill('0') << this->serialNumber << "] " <<
				"Quantity " << setfill(' ') << setw(3) << left << this->quantity << " " <<
				"Description: " << this->description << endl;

			//clean the formet
			os << setfill(' ') << right;

		}

	}


	ItemSet::ItemSet(const std::string& str) {
		size_t pos = 0;
		this->name = this->utilities.extractToken(str, pos);
		this->serialNumber = stoul(utilities.extractToken(str, pos)); // stoul convert string to unsigned int
		this->quantity = stoul(utilities.extractToken(str, pos)); // stoul convert string to unsigned int
		this->description = utilities.extractToken(str, pos);
	};

	ItemSet::ItemSet(ItemSet&& src) noexcept {
		this->name = src.name;
		this->serialNumber = src.serialNumber;
		this->quantity = src.quantity;
		this->description = src.description;

		src.name = "";
		src.serialNumber = 0u;
		src.quantity = 0u;
		src.description = "";
	}













}