/*
 * MatrixMTFProcessorFactory.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: kuba
 */

#include "MatrixMTFProcessorFactory.h"

namespace Tools {

MatrixMTFProcessorFactory::MatrixMTFProcessorFactory() :
  algorithm_name_("MTF_Matrix"){
}

MatrixMTFProcessorFactory::~MatrixMTFProcessorFactory() {
}

shared_ptr<Processor> MatrixMTFProcessorFactory::GenerateProcessor(int user_id) {
  MatrixMTFProcessor* new_processor = new MatrixMTFProcessor(user_id, algorithm_name_);
  return shared_ptr<Processor>(new_processor);
}

} /* namespace Tools */
