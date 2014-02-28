/*
 * Proccessor.h
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#ifndef TREEPROCCESSOR_H_
#define TREEPROCCESSOR_H_

#include "../Headers/Tree.h"
#include "../Headers/Elements.h"
#include "Tester.h"
#include "Processor.h"
using namespace Tree;
using std::string;

namespace Tools {

class TreeProcessor : public Processor{
 public:
  // userId - Id of user
  // identifier - name of algorithms
  TreeProcessor(int userId, string identifier = string());
  virtual ~TreeProcessor();
  // id - Receiver id
  // learn - if true no penalty is added
  virtual void Proceed(int id, bool learn = false);
  // return penalty counted by tester
  virtual int GetPenalty();
  using Processor::identifier;
  using Processor::user_id;
 private:
  // algorithms elements
  TreeRoot root_;
  TreeFactory tree_element_generator_;
  // Penalty counter
  Tester penalty_counter_;
};

} /* namespace Tree */

#endif /* TREEPROCCESSOR_H_ */