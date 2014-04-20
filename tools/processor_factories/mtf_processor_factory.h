/*
 * MTFProcessorFactory.h
 *
 *  Created on: Mar 3, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef MTFPROCESSORFACTORY_H_
#define MTFPROCESSORFACTORY_H_

#include "../processor_factory.h"
#include "../processors/mtf_processor.h"

#include <string>

using std::string;

namespace Tools {
/*
 * Factory for MTFProcessor class.
 */
class MTFProcessorFactory : public Tools::ProcessorFactory {
 public:
  MTFProcessorFactory();
  virtual ~MTFProcessorFactory();
  virtual shared_ptr<Processor> GenerateProcessor(int user_id);

 private:
  string algorithm_name_;
};

} /* namespace Tools */

#endif /* MTFPROCESSORFACTORY_H_ */
