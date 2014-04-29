#ifndef RANDOMTREEPROCESSORFACTORY_H_
#define RANDOMTREEPROCESSORFACTORY_H_

#include "../processor_factory.h"
#include "../../headers/algorithms.h"
#include "../../headers/elements.h"
#include "../judges.h"

#include <string>

using std::to_string;
namespace Tools {

/**
 * Generates RandomTreeProcessor using Tester judge and RandomTree algorithm.
 * @see Algorithms::RandomTreeRoot
 * @see Tools::Tester
 */
class RandomTreeProcessorFactory : public ProcessorFactory {
 public:
  /**
   * Sets parameter to create instance of RandomTreeProcessor,
   * especially parameters for RandomTree algorithm.
   * @param moving_up_propability Probability of moving element every one
   * level up in the tree when notified.
   * @param diff_influence Influence of difference between elements on
   * decision to move element up.
   * @see Algorithms::RandomTreeRoot
   */
  RandomTreeProcessorFactory(const double moving_up_propability = 0.75,
                             const double diff_influence = 0.5);
  virtual ~RandomTreeProcessorFactory();
  virtual shared_ptr<Processor> GenerateProcessor(int user_id);

 private:
  string algorithm_name_;
  /** Probability of moving element every one
   * level up in the tree when notified in generated RandomTreeProcessor*/
  const double MOVING_UP_PROPABILITY;

  /** Influence of difference between elements on
   * decision to move element up in generated RandomTreeProcessor */
  const double DIFF_INFLUENCE;
};

} /* namespace Tools */

#endif /* RANDOMTREEPROCESSORFACTORY_H_ */
