/*
 * InvalidIndexException.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: Jakub Banaszewski
 */

#include "invalid_index_exception.h"

namespace Exception {

InvalidIndexException::InvalidIndexException(int id)
    : id_(id),
      message_("No element with that index") {
  if (id >= 0)
    message_+= " " + Utils::ToString(id);
}

InvalidIndexException::~InvalidIndexException() {
}

} /* namespace Exception */
