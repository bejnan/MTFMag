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

int Element::Compare(Element& elem) {
  if (id_ == elem.id_)
    return 0;
  else
    return -1;
}

double Element::Difference(Element& elem) {
  return Compare(elem);
}

} /* namespace Base */
