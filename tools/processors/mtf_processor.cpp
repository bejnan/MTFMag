/*
 * MTFProcessor.cpp
 *
 *  Created on: Mar 2, 2014
 *      Author: Jakub Banaszewski
 */

#include "mtf_processor.h"

namespace Tools {

MTFProcessor::MTFProcessor(int id, string identifier)
    : Processor(id, identifier),
      penalty_counter_(Tester(20, 20)) {
}

MTFProcessor::~MTFProcessor() {
}

void MTFProcessor::Proceed(int id, bool learn) {
  int old_position = 0;
  list<shared_ptr<Base::Element> >::const_iterator element_iter;
  for (element_iter = element_list.begin(); element_iter != element_list.end();
      element_iter++) {
    ++old_position;
    if ((*element_iter)->user_id() == id) {
      break;
    }
  }
  if (element_iter == element_list.end()) {
    Base::Element* new_elem = new Base::Element(id);
    element_list.push_front(shared_ptr<Base::Element>(new_elem));
    old_position = 0;
  }
  if (!learn) {
    penalty_counter_.CountPenalty(old_position);
  }
}

int MTFProcessor::GetPenalty() {
  return penalty_counter_.OveralPenalty();
}

} /* namespace Tools */
