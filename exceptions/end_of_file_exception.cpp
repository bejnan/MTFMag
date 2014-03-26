/*
 * EndOfFileException.cpp
 *
 *  Created on: Feb 21, 2014
 *      Author: kuba
 */

#include "end_of_file_exception.h"

namespace Exception {

EndOfFileException::EndOfFileException() : message_("Meet end of fine") {
}

EndOfFileException::~EndOfFileException() {
}

} /* namespace Exception */
