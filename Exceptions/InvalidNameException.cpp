/*
 * InvalidNameException.cpp
 *
 *  Created on: 21 lut 2014
 *      Author: kuba
 */

#include "InvalidNameException.h"

namespace Exception {

InvalidNameException::InvalidNameException(string search_name) :
    message_("Name doesn't exists in database: " + search_name){
}

InvalidNameException::~InvalidNameException() {
}

} /* namespace Exception */
