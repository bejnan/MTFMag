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

/**
 * Class (more like interface) which is basic container of user friends, contacts.
 * This implementation doesn't provide meaningful order between elements.
 */
class Element {
 public:
  /**
   * Constructor with only one responsibility to initialize identifier field.
   * @param user_id Identifier of user(friend).
   */
  Element(int user_id);

  /**
   * Default destructor. Nothing to handle
   */
  virtual ~Element();

  /**
   * Return prototype of Element class to generate instances of class
   * by Close method.
   * @return Pointer to instance with identifier
   */
  static shared_ptr<Base::Element> GetPrototype();

  /**
   * Method to Compare two elements. Used to order
   * elements between themselves
   * @param elem Element to compare
   * @return 0 if elements are equal, negative value if given element have
   * bigger value, positive otherwise
   */
  virtual int Compare(Element& elem);

  /**
   *
   * @param elem
   * @return
   */
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
