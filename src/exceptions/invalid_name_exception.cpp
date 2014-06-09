/*
 * InvalidNameException.cpp
 *
 *  Created on: 21 lut 2014
 *      Author: Jakub Banaszewski
 */

#include "invalid_name_exception.h"

namespace Exception {

InvalidNameException::InvalidNameException(string search_name) :
    message_("Name doesn't exists in database: " + search_name){
}

InvalidNameException::~InvalidNameException() {
}

} /* namespace Exception */
