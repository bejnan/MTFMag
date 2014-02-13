/*
 * Element.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: kuba
 */

#include "Element.h"

namespace Base {

Element::Element(int id)
    : id_(id) {
}

Element::~Element() {
}

int Element::compare(const Element& elem) {
  if (id_ == elem.id_)
    return 0;
  else
    return -1;
}

int Element::difference(const Element& elem) {
  return compare(elem);
}

} /* namespace Base */
