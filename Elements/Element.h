/*
 * Element.h
 *
 *  Created on: Feb 11, 2014
 *      Author: kuba
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

namespace Base {

// Class containing user's data
class Element {
 public:
  // id - Element Identifier
  Element(int id);
  virtual ~Element();
  // Compare element's content
  virtual int Compare(Element& elem);
  // Difference between elements
  virtual double Difference(Element& elem);
  // Notify user choice
  virtual void Notify(int update_counter = 0) { }
  // Id getter
  int id() { return id_; }
 private:
  // user identifier
  const int id_;
};

} /* namespace Base */

#endif /* ELEMENT_H_ */
