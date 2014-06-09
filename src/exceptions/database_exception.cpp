/*
 * DatabaseException.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: Jakub Banaszewski
 */

#include "database_exception.h"

namespace Exception {

DatabaseException::DatabaseException() :
		message_("Database exception") {
}

DatabaseException::~DatabaseException() {
}

} /* namespace Base */
