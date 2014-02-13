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
//TODO Penalty Count!
 private:
  unsigned int first_page_list_size_;
  unsigned int second_page_list_size_;
  unsigned long penalty;
};

} /* namespace Tree */

#endif /* TESTER_H_ */
