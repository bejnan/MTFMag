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

int Element::compare(const Element& elem1, const Element& elem2) {
  if (elem1.id_ == elem2.id_)
    return 0;
  else
    return -1;
}

} /* namespace Base */
