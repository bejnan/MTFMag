/*
 * Tester.h
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef TESTER_H_
#define TESTER_H_

namespace Tools {
/**
 * Counter of penalties. This class assume that user used
 * screen with scroll and searching. If notified friend (element)
 * is on first page user can find it in no time. If element is on
 * second page user have to scroll to find it. If element is further
 * user uses search which finds element in constant time (MAX_PENALTY), but bigger than
 * searching on first two screens (because user have to do it anyway to know,
 * that element isn't there).
 */
class Tester {
 public:
  /**
   * Initialize penalty parameters
   * @param first_page_list_size Size of first page. Notification of elements that are located there
   * costs nothing in this model.
   * @param second_page_list_size Size of second page.Notification of elements that are located there
   * costs (position - first_page_size).
   */
  Tester(int first_page_list_size, int second_page_list_size);

  /**
   * Default destructor. Nothing to handle
   */
  virtual ~Tester();

  /**
   * Main method of counter. Check position of notified element and compare it
   * with set parameters. After that adds adequate penalty to penalty_sum_ property.
   * @param element_position Position on which element was found before notification.
   */
  virtual void CountPenalty(unsigned int element_position);

  /**
   * Getter of overall penalty
   * @return Sum of all counted penalties
   */
  virtual int penalty() { return penalty_sum_; }

 private:
  unsigned int first_page_list_size_;  /**< Size of first page
                                            (with no penalty)      */
  unsigned int second_page_list_size_; /**< Size of second page
                                            (with counted penalty) */

  unsigned const int MAX_PENALTY; /**< Penalty for elements founded
                                   further than on first two pages */
  unsigned long penalty_sum_;     /**< Sum of all penalties        */
};

} /* namespace Tree */

#endif /* TESTER_H_ */
