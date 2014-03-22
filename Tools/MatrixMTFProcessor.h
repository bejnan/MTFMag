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

class MatrixMTFProcessor : public Tools::Processor {
 public:
  MatrixMTFProcessor(int user_id, string identifier, int width = 2,
                     bool random = false);
  virtual ~MatrixMTFProcessor();

  virtual void Proceed(int user_id, bool learn = false);

  virtual int GetPenalty();

 protected :
  virtual void AddUser(int user_id);
 private:
  Tester penalty_counter_;
  shared_ptr<Matrix::MatrixBuilder> matrix_builder_;
  shared_ptr<Matrix::MTFMatrix> matrix_;
  shared_ptr<Base::Element> user_container_prototype;
};

} /* namespace Tools */

#endif /* MATRIXMTXPROCESSOR_H_ */
