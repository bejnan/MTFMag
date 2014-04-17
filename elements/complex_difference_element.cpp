/*
 * complex_difference_element.cpp
 *
 *  Created on: Apr 17, 2014
 *      Author: kuba
 */

#include "complex_difference_element.h"

namespace Base {

ComplexDifferenceElement::ComplexDifferenceElement(int user_id)
    : SimpleElement(user_id),
      last_update_(0),
      UPDATE_VALUE(0.1) {
}

ComplexDifferenceElement::~ComplexDifferenceElement() {
}

shared_ptr<Base::Element> GetPrototype() {
  Element* prototype_element = new ComplexDifferenceElement(0);
  return shared_ptr<Base::Element>(prototype_element);
}

int ComplexDifferenceElement::Compare(const ComplexDifferenceElement& elem) {
  int simple_element_compare = SimpleElement::Compare(elem);
  if (simple_element_compare == 0) {
    return last_update_ - elem.last_update_;
  } else {
    return simple_element_compare;
  }
}

double ComplexDifferenceElement::Difference(Element& elem) {
  try {
    ComplexDifferenceElement& complex_difference_elem =
        dynamic_cast<ComplexDifferenceElement&>(elem);
    return Difference(complex_difference_elem);
  } catch (bad_cast& e) {
    return SimpleElement::Compare(elem);
  }
}

void ComplexDifferenceElement::Notify(int update_counter) {
  SimpleElement::Notify();
  last_update_ = update_counter;
}

double ComplexDifferenceElement::Difference(ComplexDifferenceElement& elem) {
  double simple_diff = SimpleElement::Difference(elem);
  double nominator = (double) (last_update_ - elem.last_update_);
  double denominator = ((double) (max(last_update_, elem.last_update_)))
      * UPDATE_VALUE;
  double diff = simple_diff
      + nominator / ((denominator == 0) ? 1 : denominator);
  return diff;
}

} /* namespace Base */
