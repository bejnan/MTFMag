/*
 * InvalidIndexException.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: kuba
 */

#include "InvalidIndexException.h"

namespace Exception {

InvalidIndexException::InvalidIndexException(int id)
    : id_(id),
      message_("No element with that index") {
  if (id >= 0)
    message_+= " " + std::to_string(id);
}

InvalidIndexException::~InvalidIndexException() {
}

} /* namespace Exception */
