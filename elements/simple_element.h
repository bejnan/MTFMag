/*
 * SimpleElement.h
 *
 *  Created on: 13 gru 2013
 *      Author: Jakub Banaszewski
 */

#ifndef SIMPLEELEMENT_H_
#define SIMPLEELEMENT_H_

#include "element.h"

namespace Base {

/**
 * Element class extended by counter of
 * notifications. This influences mainly Compare and
 * Difference method. Class implementation provides
 * back compatibility to base class.
 * @see Element
 */
class SimpleElement : public Element {
 public:

  /**
   * Constructor initialize private fields (with 0 value)
   * @param user_id Identifier of user(friend).
   */
  SimpleElement(int user_id);

  /**
   * Default destructor. Nothing to handle
   */
  virtual ~SimpleElement();

  /**
   * Return prototype of SimpleElement class to generate instances of class
   * by Close method.
   * @return Pointer to instance with identifier
   * @see TreeProcessor
   * @see MatrixMTFProcessor
   */
  static shared_ptr<Base::Element> GetPrototype();

  virtual int Compare(Element& elem);

  /**
   * Counts difference between elements as difference of
   * notification counters. Every notification increase
   * counter by one. It uses private method SimpleElementDifference.
   * If elem is reference to base class then base class Difference is used.
   * @param elem Element to compare
   * @return Counts of notifications - counts of given elem notifications
   */
  virtual double Difference(Element& elem);

  virtual void Notify(int update_counter = 0);
  virtual shared_ptr<Element> Clone(int user_id);
  using Element::user_id;

 private:
  /**
   * Implementation of Compare between SimpleElement class instances
   * @see Compare
   */
  int SimpleElementCompare(SimpleElement& elem);

  /**
   * Implementation of Difference between SimpleElement class instances
   * @see Difference
   */
  double SimpleElementDifference(SimpleElement& elem);

  int notification_counter_; /**< how many times element was notified */
};

} /* namespace Devel */

#endif /* SIMPLEELEMENT_H_ */
