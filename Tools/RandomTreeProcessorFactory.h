/*
 * RandomTreeProcessorFactory.h
 *
 *  Created on: 3 mar 2014
 *      Author: kuba
 */

#ifndef RANDOMTREEPROCESSORFACTORY_H_
#define RANDOMTREEPROCESSORFACTORY_H_

#include "ProcessorFactory.h"
#include "RandomTreeProcessor.h"

#include <string>

using std::to_string;
namespace Tools {
/*
 * Factory for RandomTreeProcessor
 */
class RandomTreeProcessorFactory : public ProcessorFactory {
 public:
  RandomTreeProcessorFactory(const double moving_up_propability = 0.75,
                             const double diff_influence = 0.5);
  virtual ~RandomTreeProcessorFactory();
  virtual shared_ptr<Processor> GenerateProcessor(int user_id);

 private:
  string algorithm_name_;
  const double MOVING_UP_PROPABILITY;
  const double DIFF_INFLUENCE;
};

} /* namespace Tools */

#endif /* RANDOMTREEPROCESSORFACTORY_H_ */
