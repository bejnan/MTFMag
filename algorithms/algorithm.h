/*
 * algorithm.h
 *
 *  Created on: Apr 22, 2014
 *      Author: kuba
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "../headers/elements.h"

#include <memory>

using std::shared_ptr;

namespace Base {

/**
 * Interface for all algorithms.
 * Every implementation algorithm (child class) should be able to
 * produce linear order between elements.
 */
class Algorithm {
 public:
  virtual ~Algorithm() {
  }
  ;

  /**
   * Main method of class. Notify element with given id.
   * After notification of element (Element::Notify method)
   * it moves element to front. Details of movement depends on algorithm.
   * @param user_id Identifier of element to notify
   */
  virtual void NotifyContent(int user_id) = 0;

  virtual void NotifyContent(int user_id, int notification_count) = 0;

  virtual int GetContentPosition(int user_id) = 0;

  /**
   * Adds new element to algorithm's collection if no element with given identifier
   * is already added.
   * @param user_id Identifier of new element.
   */
  virtual void AddElement(int user_id) = 0;
};

}

#endif /* ALGORITHM_H_ */
