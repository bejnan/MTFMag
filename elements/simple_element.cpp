/*
 * SimpleElement.cpp
 *
 *  Created on: 13 gru 2013
 *      Author: kuba
 */

#include "simple_element.h"

#include <typeinfo>
#include <algorithm>

using std::bad_cast;
using std::max;

namespace Base {

SimpleElement::SimpleElement(int id)
    : Element(id),
      last_update_(0),
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
    return Compare(simple_elem);
  } catch (bad_cast& e) {
    return elem.Compare(*this);
  }
}

double SimpleElement::Difference(Element& elem) {
  try {
    SimpleElement& simple_elem = dynamic_cast<SimpleElement&>(elem);
    return Difference(simple_elem);
  } catch (bad_cast& e) {
    return elem.Difference(*this);
  }
}

void SimpleElement::Notify(int update_counter) {
  ++notification_counter_;
  last_update_ = update_counter;
}

shared_ptr<Element> SimpleElement::Clone(int user_id) {
  Element* new_element = new SimpleElement(user_id);
  return shared_ptr<Element>(new_element);
}

int SimpleElement::Compare(const SimpleElement& elem) {
  if (notification_counter_ == elem.notification_counter_) {
    return (last_update_ - elem.last_update_);
  } else {
    return (notification_counter_ - elem.notification_counter_);
  }
}

double SimpleElement::Difference(const SimpleElement& elem) {
  double diff = (double) (notification_counter_ - elem.notification_counter_)
      / (double) (notification_counter_ + elem.notification_counter_);
  diff += ((double) (last_update_ - elem.last_update_)
      / (double) (max(last_update_, elem.last_update_)) * UPDATE_VALUE);
  return diff;
}

} /* namespace Base */
