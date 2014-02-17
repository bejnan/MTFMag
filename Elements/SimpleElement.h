/*
 * SimpleElement.h
 *
 *  Created on: 13 gru 2013
 *      Author: kuba
 */

#ifndef SIMPLEELEMENT_H_
#define SIMPLEELEMENT_H_

#include "Element.h"

namespace Base {

class SimpleElement: public Element {
public:
  SimpleElement(int id);
  ~SimpleElement();

  virtual int Compare(Element& elem);
  virtual double Difference(Element& elem);
  virtual void Notify(int update_counter = 0);
  using Element::id;

private :
  int Compare(const SimpleElement& elem);
  double Difference(const SimpleElement& elem);
  int last_update_;
  int notification_counter_;
  static constexpr double UPDATE_VALUE = 0.1;
};

} /* namespace Devel */

#endif /* SIMPLEELEMENT_H_ */
