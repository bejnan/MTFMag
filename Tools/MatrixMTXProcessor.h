/*
 * MatrixMTXProcessor.h
 *
 *  Created on: Mar 20, 2014
 *      Author: kuba
 */

#ifndef MATRIXMTXPROCESSOR_H_
#define MATRIXMTXPROCESSOR_H_

#include "Processor.h"
#include "../Matrix/MTFMatrix.h"
#include "../Matrix/MatrixBuilder.h"
#include "Tester.h"

#include <memory>

using std::shared_ptr;

namespace Tools {

class MatrixMTXProcessor : public Tools::Processor {
 public:
  MatrixMTXProcessor(int user_id, string identifier, int width = 2,
                     bool random = false);
  virtual ~MatrixMTXProcessor();

  virtual void Proceed(int id, bool learn = false);

  virtual int GetPenalty();

 private:
  Tester penalty_counter_;
  shared_ptr<Matrix::MatrixBuilder> matrix_builder_;
  shared_ptr<Matrix::MTFMatrix> matrix_;
};

} /* namespace Tools */

#endif /* MATRIXMTXPROCESSOR_H_ */
