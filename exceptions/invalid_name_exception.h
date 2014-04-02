/*
 * InvalidNameException.h
 *
 *  Created on: 21 lut 2014
 *      Author: Jakub Banaszewski
 */

#ifndef INVALIDNAMEEXCEPTION_H_
#define INVALIDNAMEEXCEPTION_H_

#include "database_exception.h"

#include <string>

using std::string;

namespace Exception {

class InvalidNameException: public DatabaseException {
public:
	InvalidNameException(string search_name = "");
	virtual ~InvalidNameException();

	const char * what() const throw() {
	    return message_.c_str();
	  }
private:
	string message_;
};

} /* namespace Exception */

#endif /* INVALIDNAMEEXCEPTION_H_ */
