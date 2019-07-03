#include "Utilities.h"
#include <string>
using namespace std;
namespace sict {


	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
		size_t nextDelimiterPos = str.find(delimiter, next_pos);
		string tempToken;

		//This function reports an exception if one delimiter follows another without any token between them.
		if (nextDelimiterPos - next_pos == 0)
		{
			throw "one delimiter follows another without any token between them";
		}
		else if (nextDelimiterPos == string::npos) {
			tempToken = str.substr(next_pos);
			//If not, this function returns the position that is beyond the end of the string
			nextDelimiterPos = str.size() - 1;
		}
		else {
			// find next delimiter and token
			tempToken = str.substr(next_pos, nextDelimiterPos - next_pos);

			//check width without description
			//compares the size of the extracted token to the field width currently stored in the objectand 
			//if the size of the token is greater than that width increases that width.
			if (tempToken.size() > this->width)
			{
				this->width = tempToken.size();
			}
		}

		next_pos = nextDelimiterPos + 1; // change the position for next token
		return tempToken;
	}


	const char Utilities::getDelimiter() const {
		return delimiter;
	}

	size_t Utilities::getFieldWidth() const {

		return width;
	}

	void Utilities::setDelimiter(const char d) {
		delimiter = d;
	}

	void Utilities::setFieldWidth(size_t size) {
		width = size;
	}

}//!sict