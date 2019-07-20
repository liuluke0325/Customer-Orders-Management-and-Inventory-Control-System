/*
Hsueh Chih Liu
116131186
07/19/2019
MS2
*/

#ifndef SICT_CUSTOMERORDER_H
#define SICT_CUSTOMERORDER_H
#include <string>
#include "ItemSet.h"
#include <iostream>
#include <vector>
namespace sict {

	class CustomerOrder {
		//managing and processing customer orders
		Utilities utilities;
		std::string customerName;
		std::string productName;
		static size_t width;
		struct ItemInfo {
			std::string name;
			unsigned int serialNumber = 0u;
			bool filled = false;
		} *ptrItemInfo;

		size_t itemInfoCounter = 0;
		

	public:
		CustomerOrder();
		CustomerOrder(const std::string& src);
		~CustomerOrder();
		void fillItem(ItemSet& item, std::ostream& os);
		bool isFilled() const;
		bool isItemFilled(const std::string& item) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail = false) const;

		//Customer order objects are unique and hence neither copyable nor copy-assignable. 
		//However, they are both movable and move-assignable.
		CustomerOrder(const CustomerOrder& src) = delete;
		CustomerOrder& operator = (const CustomerOrder& src) = delete;
		CustomerOrder(CustomerOrder&& src);
		CustomerOrder& operator = (CustomerOrder&& src) noexcept;
	};





} //!sict


#endif // !SICT_CUSTOMERORDER_H


