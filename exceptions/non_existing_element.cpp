/*
 * non_existing_element.cpp
 *
 *  Created on: May 22, 2014
 *      Author: kuba
 */

#include "non_existing_element.h"

using std::to_string;
namespace Exception {

NonExistingElement::NonExistingElement(int id)
    : message_("Element with given identifier doesn't exists") {
  if (id != 0) {
    message_ += " : " + to_string(id);
  }
}

NonExistingElement::~NonExistingElement() {

}

} /* namespace Exception */
