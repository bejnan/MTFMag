/*
 * Tester.h
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#ifndef TESTER_H_
#define TESTER_H_

namespace Tools {
/**
 * Class counts penalty
 */
class Tester {
 public:
  // first_page_list_size - list of elements with no penalty
  // second_page_list_size - list of elements with counted penalty
  Tester(int first_page_list_size, int second_page_list_size);
  virtual ~Tester();
  // As written before, if element_position is less then first_page_list_size, no penalty is added.
  // If element is on second_page_list_size, penalty is position - first_page_list_size.
  // If element_position is more than two pages then MAX_PENALTY is added.
  virtual void CountPenalty(unsigned int element_position);
  virtual int penalty() { return penalty_; }
 private:
  unsigned int first_page_list_size_;
  unsigned int second_page_list_size_;
  // Const penalty for elements more distant than first and second page list
  unsigned const int MAX_PENALTY;
  // Sum of penalties
  unsigned long penalty_;
};

} /* namespace Tree */

#endif /* TESTER_H_ */
