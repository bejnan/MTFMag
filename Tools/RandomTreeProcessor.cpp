/*
 * RandomTreeProcessor.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: kuba
 */

#include "RandomTreeProcessor.h"

namespace Tools {

RandomTreeProcessor::RandomTreeProcessor(int user_id, string identifier)
    : Processor(user_id, identifier),
      root_(RandomTreeRoot()),
      tree_element_generator_(root_),
      penalty_counter_(Tester(20, 20)) {

}

RandomTreeProcessor::~RandomTreeProcessor() {
}

void RandomTreeProcessor::Proceed(int id, bool learn) {
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

int RandomTreeProcessor::GetPenalty() {
  return penalty_counter_.penalty();
}


} /* namespace Tools */
