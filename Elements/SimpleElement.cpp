/*
 * SimpleElement.cpp
 *
 *  Created on: 13 gru 2013
 *      Author: kuba
 */

#include "SimpleElement.h"

#include <typeinfo>

using std::bad_cast;

namespace Base {

SimpleElement::SimpleElement(int id)
    : Element(id),
      last_update_(0),
      notification_counter_(0) {
}

SimpleElement::~SimpleElement() {
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

int SimpleElement::Compare(const SimpleElement& elem) {
  if (notification_counter_ == elem.notification_counter_) {
    return (last_update_ - elem.last_update_);
  } else {
    return (notification_counter_ - elem.notification_counter_);
  }
}

double SimpleElement::Difference(const SimpleElement& elem) {
  double diff = notification_counter_ - elem.notification_counter_;
  diff += ((last_update_ - elem.last_update_) / UPDATE_VALUE);
  return diff;
}

} /* namespace Base */