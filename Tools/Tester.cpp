/*
 * Tester.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "Tester.h"

namespace Tools {

Tester::Tester(int first_page_list_size, int second_page_list_size)
    : first_page_list_size_(first_page_list_size),
      second_page_list_size_(second_page_list_size),
      MAX_PENALTY((first_page_list_size + second_page_list_size) * 2),
      penalty_(0) {
}

Tester::~Tester() {
}

void Tester::CountPenalty(unsigned int element_position)
{
  if (element_position < first_page_list_size_)
    return;
  element_position -= first_page_list_size_;
  if (element_position < second_page_list_size_)
    penalty_ += element_position +1;
  else
    penalty_ += MAX_PENALTY;
}



} /* namespace Tree */
