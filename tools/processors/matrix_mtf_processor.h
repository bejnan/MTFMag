/*
 * MatrixMTXProcessor.h
 *
 *  Created on: Mar 20, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef MATRIXMTXPROCESSOR_H_
#define MATRIXMTXPROCESSOR_H_

#include "../processor.h"
#include "../../headers/algorithms.h"
#include "../tester.h"

#include <memory>

using std::shared_ptr;

namespace Tools {

class MatrixMTFProcessor : public Tools::Processor {
 public:
  MatrixMTFProcessor(int user_id, string identifier, int width = 2);
  virtual ~MatrixMTFProcessor();

  virtual void Proceed(int user_id, bool learn = false);

  virtual int GetPenalty();

 protected:
  virtual void AddUser(int user_id);
 private:
  Tester penalty_counter_;
  shared_ptr<Algorithms::MTFMatrix> matrix_;
};

} /* namespace Tools */

#endif /* MATRIXMTXPROCESSOR_H_ */
