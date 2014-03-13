/*
 * MatrixBuilder.h
 *
 *  Created on: Mar 13, 2014
 *      Author: kuba
 */

#ifndef MATRIXBUILDER_H_
#define MATRIXBUILDER_H_

#include <memory>

#include "MTFMatrix.h"

using std::shared_ptr;

namespace Matrix {

class MatrixBuilder {
 public:
  virtual ~MatrixBuilder();

  shared_ptr<MatrixBuilder> GetInstance();
  shared_ptr<MatrixBuilder> WithMatrixWidth(int width);
  shared_ptr<MatrixBuilder> WithRandomAdding();
  shared_ptr<MatrixBuilder> ResetSetting();

  shared_ptr<MTFMatrix> Generate();

 protected:
  MatrixBuilder();
 private:
  int matrix_width_;
  bool with_random_;

};

} /* namespace Matrix */

#endif /* MATRIXBUILDER_H_ */
