/*
 * TreeProcessorFactory.h
 *
 *  Created on: 28 lut 2014
 *      Author: kuba
 */

#ifndef TREEPROCESSORFACTORY_H_
#define TREEPROCESSORFACTORY_H_

#include "ProcessorFactory.h"

namespace Tools {

class TreeProcessorFactory : public Tools::ProcessorFactory {
 public:
  TreeProcessorFactory();
  virtual ~TreeProcessorFactory();
  virtual shared_ptr<Processor> GenerateProcessor(int id);
 private :
  const string algorithm_name_;
};

} /* namespace Exception */

#endif /* TREEPROCESSORFACTORY_H_ */
