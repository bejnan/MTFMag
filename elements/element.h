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
 * Element class and it's deriving classes support cloning to be part of Prototype
 * pattern.
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
   * Measure how much Elements are different between each other.
   * Used to define order between elements.
   * @param elem Element to compare
   * @return Value represents difference between element. Details depends on child class.
   */
  virtual double Difference(Element& elem);


  /**
   * Gives element change to save last use of it.
   * @param update_counter Counter on which update was element last notified
   */
  virtual void Notify(int update_counter = 0) { }

  /**
   * Method to use Prototype pattern in
   * @param user_id
   * @return
   */
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
