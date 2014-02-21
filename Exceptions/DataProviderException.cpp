/*
 * DataProviderException.cpp
 *
 *  Created on: Feb 21, 2014
 *      Author: kuba
 */

#include "DataProviderException.h"

namespace Exception {

DataProviderException::DataProviderException() : message_("Data provider exception\n") {
}

DataProviderException::~DataProviderException() {
}

} /* namespace Exception */
