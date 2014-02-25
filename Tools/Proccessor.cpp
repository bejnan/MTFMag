/*
 * Proccessor.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "Proccessor.h"

namespace Tools {

Processor::Processor(int user_id, string identifier)
    : user_id_(user_id),
      identifier_(identifier),
      root_(TreeRoot()),
      tree_element_generator_(root_),
      penalty_counter_(Tester(20, 20)) {
}

Processor::~Processor() {
}

void Processor::Proceed(int id, bool learn) {
  int position = root_.GetContentPosition(id);
  if (position < 0) {
    tree_element_generator_.AddElement<Base::SimpleElement>(id);
    position = 0;
  }
  if (!learn) {
    penalty_counter_.CountPenalty(position);
  }
  root_.NotifyContent(id);
}

int Processor::GetPenalty() {
  return penalty_counter_.penalty();
}

} /* namespace Tree */
