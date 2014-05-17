/*
 * Tester.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#include "tester.h"

namespace Tools {

Tester::Tester(int first_page_list_size, int second_page_list_size)
    : first_page_list_size_(first_page_list_size),
      second_page_list_size_(second_page_list_size),
      MAX_PENALTY((first_page_list_size + second_page_list_size) * 2),
      turn_counter(0),
      penalty_sum_(0) {
}

Tester::~Tester() {
}

void Tester::CountPenalty(unsigned int element_position) {
  ++turn_counter;
  if (element_position <= first_page_list_size_)
    return;
  int penalty = 0;
  element_position -= first_page_list_size_;
  if (element_position < second_page_list_size_) {
    penalty = element_position;
  } else {
    penalty += MAX_PENALTY;
  }
  penalty_sum_ += penalty;
  pair<int, int> penalty_pair(penalty, turn_counter);
  penalties_.push_back(penalty_pair);
}

list<pair<int, int> > Tester::PenaltyDetails() {
  return penalties_;
}

shared_ptr<Judge> Tester::Clone() {
  Judge* new_judge_instance = new Tester(first_page_list_size_,second_page_list_size_);
  return shared_ptr<Judge>(new_judge_instance);
}

} /* namespace Tools */
