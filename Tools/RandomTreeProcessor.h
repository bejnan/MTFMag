/*
 * RandomTreeProcessor.h
 *
 *  Created on: 3 mar 2014
 *      Author: kuba
 */

#ifndef RANDOMTREEPROCESSOR_H_
#define RANDOMTREEPROCESSOR_H_

#include "../Headers/Tree.h"
#include "../Headers/Elements.h"
#include "Tester.h"
#include "Processor.h"

using namespace Tree;
using std::string;

namespace Tools {

class RandomTreeProcessorFactory;

class RandomTreeProcessor : public Processor {
  friend class RandomTreeProcessorFactory;
 public:
  virtual ~RandomTreeProcessor();
  virtual void Proceed(int id, bool learn = false);
  virtual int GetPenalty();
  using Processor::identifier;
  using Processor::user_id;
 private:
   RandomTreeProcessor(int user_id, string identifier);
   // algorithms elements
    RandomTreeRoot root_;
    TreeFactory tree_element_generator_;
    // Penalty counter
    Tester penalty_counter_;
};

} /* namespace Tools */

#endif /* RANDOMTREEPROCESSOR_H_ */
