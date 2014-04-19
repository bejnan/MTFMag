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

/**
 * Element class extended by counter of notifications
 * (from SimpleElement class) and counter of updates (remembers last update of
 * element). This influences mainly Compare and
 * Difference method. Class implementation provides
 * back compatibility to parent classes.
 * @see SimpleElement
 */
class ComplexDifferenceElement : public SimpleElement {
 public:

  /**
   * Constructor initialize private fields (with 0 value)
   * @param user_id Identifier of user(friend).
   */
  ComplexDifferenceElement(int user_id);

  /**
   * Default destructor. Nothing to handle
   */
  virtual ~ComplexDifferenceElement();

  /**
   * Return prototype of ComplexDifferenceElement class to generate instances of class
   * by Close method.
   * @return Pointer to instance with identifier
   * @see TreeProcessor
   * @see MatrixMTFProcessor
   */
  static shared_ptr<Base::Element> GetPrototype();

  virtual int Compare(Element& elem);

  /**
   * Similar to SimpleElement class, but with influence of
   * time of last notification.
   * @param elem Element to compare
   * @return linear combination of last update counter and
   * count of notifications
   * @see SimpleElement::Difference
   */
  virtual double Difference(Element& elem);

  virtual void Notify(int update_counter = 0);
  virtual shared_ptr<Element> Clone(int user_id);
  using Element::user_id;

 private:
  int ComplexDifferenceCompare(ComplexDifferenceElement& elem);
  double ComplexDifference(ComplexDifferenceElement& elem);

  int last_update_;     /**< Last update counter (bigger is newer)*/

  static constexpr double UPDATE_VALUE = 0.1; /** < how important is update
                      counter (bigger value => more important recent update).
                      This value is now factor for testing without any
                      theoretical prove that it is improvement        */
};

} /* namespace Tools */

#endif /* COMPLEX_DIFFERENCE_ELEMENT_H_ */
