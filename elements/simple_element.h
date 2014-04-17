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
 * Development of Element class to count frequency of
 * notification
 */
class SimpleElement : public Element {
 public:
  SimpleElement(int user_id);
  ~SimpleElement();

  static shared_ptr<Base::Element> GetPrototype();
  virtual int Compare(Element& elem);
  virtual double Difference(Element& elem);
  virtual void Notify();
  virtual shared_ptr<Element> Clone(int user_id);
  using Element::user_id;

 private:
  int SimpleElementCompare(SimpleElement& elem);
  double SimpleElementDifference(SimpleElement& elem);
  // how many times element was notificated
  int notification_counter_;
  // how important is update counter (bigger value => more important recent update)
  static constexpr double UPDATE_VALUE = 0.1;
};

} /* namespace Devel */

#endif /* SIMPLEELEMENT_H_ */
