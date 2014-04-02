/*
 * Proccessor.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#include "tree_proccessor.h"

namespace Tools {

TreeProcessor::TreeProcessor(int user_id, string identifier)
    : Processor(user_id, identifier),
      root_(Base::SimpleElement::GetPrototype()),
      penalty_counter_(Tester(20, 20)) {
}

TreeProcessor::~TreeProcessor() {
}

void TreeProcessor::Proceed(int id, bool learn) {
  int position = root_.GetContentPosition(id);
  if (position < 0) {
    root_.AddElement(id);
    position = 0;
  }
  if (!learn) {
    penalty_counter_.CountPenalty(position);
  }
  root_.NotifyContent(id);
}

int TreeProcessor::GetPenalty() {
  return penalty_counter_.penalty();
}

} /* namespace Tree */
