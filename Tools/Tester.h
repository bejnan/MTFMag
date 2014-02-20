/*
 * Tester.h
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#ifndef TESTER_H_
#define TESTER_H_

namespace Tools {

class Tester {
 public:
  Tester(int first_page_list_size, int second_page_list_size);
  virtual ~Tester();
  virtual void CountPenalty(int element_position);
  virtual int penalty() { return penalty_; }
 private:
  unsigned int first_page_list_size_;
  unsigned int second_page_list_size_;
  unsigned const int MAX_PENALTY;
  unsigned long penalty_;
};

} /* namespace Tree */

#endif /* TESTER_H_ */
