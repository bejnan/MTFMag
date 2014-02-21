/*
 * DatabaseException.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: kuba
 */

#include "DatabaseException.h"

namespace Exception {

DatabaseException::DatabaseException() :
		message_("Database exception") {
}

DatabaseException::~DatabaseException() {
}

} /* namespace Base */
