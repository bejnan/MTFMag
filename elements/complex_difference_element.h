/*
 * complex_difference_element.h
 *
 *  Created on: Apr 17, 2014
 *      Author: kuba
 */

#ifndef COMPLEX_DIFFERENCE_ELEMENT_H_
#define COMPLEX_DIFFERENCE_ELEMENT_H_

#include "simple_element.h"


using std::bad_cast;
using std::max;

namespace Base {

class ComplexDifferenceElement : public Base::SimpleElement {
 public:
  ComplexDifferenceElement(int user_id);
  virtual ~ComplexDifferenceElement();

  static shared_ptr<Base::Element> GetPrototype();
  virtual int Compare(Element& elem);
  virtual double Difference(Element& elem);
  virtual void Notify(int update_counter = 0);
  virtual shared_ptr<Element> Clone(int user_id);
  using Element::user_id;

 private:
  int ComplexDifferenceCompare(ComplexDifferenceElement& elem);
  double ComplexDifference(ComplexDifferenceElement& elem);
  // last_update counter (bigger is newer)
  int last_update_;
  // how important is update counter (bigger value => more important recent update)
  static constexpr double UPDATE_VALUE = 0.1;
};

} /* namespace Tools */

#endif /* COMPLEX_DIFFERENCE_ELEMENT_H_ */
