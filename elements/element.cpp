/*
 * Element.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: kuba
 */

#include "element.h"

namespace Base {

Element::Element(int user_id)
    : user_id_(user_id) {
}

Element::~Element() {
}

shared_ptr<Base::Element> Element::GetPrototype() {
  Element* prototype_element = new Element(0);
  return shared_ptr<Base::Element>(prototype_element);
}

int Element::Compare(Element& elem) {
  if (user_id_ == elem.user_id_)
    return 0;
  else
    return -1;
}

double Element::Difference(Element& elem) {
  return Compare(elem);
}

shared_ptr<Element> Element::Clone(int user_id) {
  Element* new_element = new Element(user_id);
  return shared_ptr<Element>(new_element);
}

} /* namespace Base */
