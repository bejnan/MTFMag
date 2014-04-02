/*
 * Element.h
 *
 *  Created on: Feb 11, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <memory>

using std::shared_ptr;

namespace Base {

// Class containing user's data
class Element {
 public:
  // id - Element Identifier
  Element(int user_id);
  virtual ~Element();
  static shared_ptr<Base::Element> GetPrototype();
  // Compare element's content
  virtual int Compare(Element& elem);
  // Difference between elements
  virtual double Difference(Element& elem);
  // Notify user choice
  virtual void Notify(int update_counter = 0) { }
  // Clone method for Prototype pattern
  virtual shared_ptr<Element> Clone(int user_id);
  // Id getter
  int user_id() {
    return user_id_;
  }
 private:
  // user identifier
  const int user_id_;
};

} /* namespace Base */

#endif /* ELEMENT_H_ */
