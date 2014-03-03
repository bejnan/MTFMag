/*
 * MTFProcessorFactory.h
 *
 *  Created on: Mar 3, 2014
 *      Author: kuba
 */

#ifndef MTFPROCESSORFACTORY_H_
#define MTFPROCESSORFACTORY_H_

#include "ProcessorFactory.h"
#include "MTFProcessor.h"

#include <string>

using std::string;
namespace Tools {

class MTFProcessorFactory : public Tools::ProcessorFactory {
 public:
  MTFProcessorFactory();
  virtual ~MTFProcessorFactory();
  virtual shared_ptr<Processor> GenerateProcessor(int id);
 private :
  string algorithm_name_;
};

} /* namespace Tools */

#endif /* MTFPROCESSORFACTORY_H_ */
