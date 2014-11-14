/*
 * ElementAlreadyExists.cpp
 *
 *  Created on: May 22, 2014
 *      Author: kuba
 */

#include "element_already_exists.h"
#include "../utils/utils.h"

namespace Exception {

ElementAlreadyExists::ElementAlreadyExists(int id)
    : message_("Duplicate identifier exception") {
  if (id != 0)
  {
    message_ += " " + Utils::ToString(id);
  }
}

} /* namespace Exception */
