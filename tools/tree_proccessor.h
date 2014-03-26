/*
 * Proccessor.h
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#ifndef TREEPROCCESSOR_H_
#define TREEPROCCESSOR_H_

#include "../headers/tree.h"
#include "../headers/elements.h"
#include "tester.h"
#include "processor.h"
using namespace Tree;
using std::string;

namespace Tools {

// class that generates TreeProcessors
class TreeProcessorFactory;

/**
 * Processor based on tree structure.
 * It works like Move To Front, but Move To Top Of Tree is
 * the best words to describe how it works.
 *
 * It uses TreeRoot as data structure with
 * TreeFactory to generate new elements
 */
class TreeProcessor : public Processor {
  friend class TreeProcessorFactory;
 public:
  virtual ~TreeProcessor();
  // id - Receiver id
  // learn - if true no penalty is added
  virtual void Proceed(int id, bool learn = false);
  // return penalty counted by tester
  virtual int GetPenalty();
  using Processor::identifier;
  using Processor::user_id;

 private:
  // userId - Id of user
  // identifier - name of algorithms
  TreeProcessor(int userId, string identifier = string());

  // algorithms elements
  TreeRoot root_;
  // Penalty counter
  Tester penalty_counter_;
};

} /* namespace Tools */

#endif /* TREEPROCCESSOR_H_ */
