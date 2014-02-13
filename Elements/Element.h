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
  virtual int compare(const Element& elem);
  // Difference between elements
  virtual int difference(const Element& elem);
 private:
  // user identifier
  const int id_;
};

} /* namespace Base */

#endif /* ELEMENT_H_ */
