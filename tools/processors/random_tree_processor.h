/*
 * RandomTreeProcessor.h
 *
 *  Created on: 3 mar 2014
 *      Author: Jakub Banaszewski
 */

#ifndef RANDOMTREEPROCESSOR_H_
#define RANDOMTREEPROCESSOR_H_

#include "../../headers/algorithms.h"
#include "../../headers/elements.h"
#include "../tester.h"
#include "../processor.h"

using namespace Algorithms;
using std::string;

namespace Tools {

// Generator of RandomTreeProcessor instances
class RandomTreeProcessorFactory;

/**
 * It is processor similar to TreeProcessor.
 * The difference is to add random decisions how high element is push
 * in tree during notification.
 */
class RandomTreeProcessor : public Processor {
  friend class RandomTreeProcessorFactory;
 public:
  virtual ~RandomTreeProcessor();
  virtual void Proceed(int id, bool learn = false);
  virtual int GetPenalty();
  using Processor::algorithm_identifier;
  using Processor::user_id;
 private:
  // only RandomTreeProcessorFactory can create this object
  RandomTreeProcessor(int user_id, string identifier,
                      const double moving_up_propability = 0.75,
                      const double diff_influence = 0.5);
  // algorithms elements
  RandomTreeRoot root_;
  // Penalty counter
  Tester penalty_counter_;
};

} /* namespace Tools */

#endif /* RANDOMTREEPROCESSOR_H_ */
