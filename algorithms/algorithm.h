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
#include <map>

using std::map;
using std::shared_ptr;
using std::string;

namespace Algorithms {

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
   * Main method of algorithm. Notify element with given id.
   * After notification of element (Base::Element::Notify method)
   * it moves element to front. Details of movement depends on algorithm.
   * @param user_id Identifier of element to notify
   */
  virtual void NotifyContent(int user_id) = 0;

  /**
   * As version with one parameter notify element with given id.
   * After notification of element (Base::Element::Notify method)
   * it moves element to front. Details of movement depends on algorithm.
   * notification_count can be used in Element::Notify method to
   * measure actuality of element.
   * @param user_id Identifier of element to notify
   * @param notification_count Timestamp or notification_count, measure to determine
   * moment in time of element notification.
   */
  virtual void NotifyContent(int user_id, int notification_count) = 0;

  /**
   * Gives current position of element in prepared algorithm order.
   * @param user_id Identifier of element
   * @return Position of element in linear order
   */
  virtual int GetContentPosition(int user_id) = 0;

  /**
   * Adds new element to algorithm's collection if no element with given identifier
   * is already added.
   * @param user_id Identifier of new element.
   */
  virtual void AddElement(int user_id) = 0;

  /**
   * Check if element with given identifier is stored
   * in algorithm collection.
   * @param user_id Identifier of element
   * @return True if element with given identifier was added to algorithm,
   * false otherwise
   */
  virtual bool HaveElement(int user_id) = 0;

  /**
   * Implementation of Prototype pattern. Creates new empty instance of
   * algorithm.
   * @return New empty instance of algorithm implementation (the same
   * as called one).
   */
  virtual shared_ptr<Algorithm> Clone() = 0;

 protected:
  /**
   * Method to move element from given position to front (depends on algorithm).
   * @param position Position of element to move
   */
  virtual void MoveFromPositionToFront(int position) = 0;

  /**
   * Method to switch pointers of elements stored in algorithm.
   * @param position1 Position of first element
   * @param position2 Position of second element
   */
  virtual void SwapElementsOnPositions(int position1, int position2) = 0;

  /**
   * Sorts elements in row to restore linear order.
   * Used after notification
   */
  virtual void SortElementToList() = 0;

  /**
   * Compares elements by Element::Compare method.
   * Element from position1 is "source" of method.
   * @param position1 Position of first element to compare.
   * @param position2 Position of second element to compare with.
   * @return Result of Element::Compare method
   * @see Base::Element::Compare
   */
  virtual int CompareElementsOnPositions(int position1, int position2) = 0;

  /**
   * Compares elements by Element::Difference method
   * Element from position1 is "source" of method.
   * @param position1 Position of first element to compare.
   * @param position2 Position of second element to compare with.
   * @return Result of Element::Difference method
   * @see Base::Element::Difference
   */
  virtual double DifferenceBetweenElementsOnPosition(int position1,
                                                     int position2) = 0;

};

}

#endif /* ALGORITHM_H_ */
