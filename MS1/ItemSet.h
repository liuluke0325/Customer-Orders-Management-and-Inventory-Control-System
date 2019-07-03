#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H
#include <string>
#include <iostream>
#include <vector>
#include "Utilities.h"
namespace sict {
	//ItemSet for managing the stock inventory of a particular item.
	class ItemSet {
		std::string name;
		unsigned int serialNumber;
		unsigned int quantity;
		std::string description;
		Utilities utilities;
	public:

		ItemSet(const std::string& str);
		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		ItemSet& operator--();
		void display(std::ostream& os, bool full) const;
		ItemSet(ItemSet&& src) noexcept;

		//Your design disables copy and move assignment operations and copy construction of the list.
		ItemSet& operator= (const ItemSet&) = delete;
		ItemSet& operator= (ItemSet&&) = delete;
		ItemSet(const ItemSet&) = delete;
	};




}//!sict





#endif // !SICT_ITEMSET_H
