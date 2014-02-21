/*
 * FilepathException.cpp
 *
 *  Created on: Feb 21, 2014
 *      Author: kuba
 */

#include "FilepathException.h"

namespace Exception {

FilepathException::FilepathException(string path) : message_("Coudn't find file on given path: " + path) {
}

FilepathException::~FilepathException() {
}

} /* namespace Exception */
