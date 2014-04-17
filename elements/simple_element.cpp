/*
 * SimpleElement.cpp
 *
 *  Created on: 13 gru 2013
 *      Author: Jakub Banaszewski
 */

#include "simple_element.h"

#include <typeinfo>
#include <algorithm>

using std::bad_cast;
using std::max;

namespace Base {

SimpleElement::SimpleElement(int id)
    : Element(id),
      notification_counter_(0) {
}

SimpleElement::~SimpleElement() {
}

shared_ptr<Base::Element> SimpleElement::GetPrototype() {
  Element* prototype_element = new SimpleElement(0);
  return shared_ptr<Base::Element>(prototype_element);
}

int SimpleElement::Compare(Element& elem) {
  try {
    SimpleElement& simple_elem = dynamic_cast<SimpleElement&>(elem);
    return SimpleElementCompare(simple_elem);
  } catch (bad_cast& e) {
    return Element::Compare(elem);
  }
}

double SimpleElement::Difference(Element& elem) {
  try {
    SimpleElement& simple_elem = dynamic_cast<SimpleElement&>(elem);
    return SimpleElementDifference(simple_elem);
  } catch (bad_cast& e) {
    return elem.Difference(*this);
  }
}

void SimpleElement::Notify() {
  ++notification_counter_;
}

shared_ptr<Element> SimpleElement::Clone(int user_id) {
  Element* new_element = new SimpleElement(user_id);
  return shared_ptr<Element>(new_element);
}

int SimpleElement::SimpleElementCompare(SimpleElement& elem) {
  return (notification_counter_ - elem.notification_counter_);
}

double SimpleElement::SimpleElementDifference(SimpleElement& elem) {
  double diff = (double) (notification_counter_ - elem.notification_counter_)
      / (double) (notification_counter_ + elem.notification_counter_);
  return diff;
}

} /* namespace Base */
