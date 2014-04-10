/*
 * MatrixBuilder.h
 *
 *  Created on: Mar 13, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef MATRIXBUILDER_H_
#define MATRIXBUILDER_H_

#include <memory>

#include "mtf_matrix.h"
#include "../headers/elements.h"

using std::shared_ptr;

namespace Matrix {
/**
 * Class to build MTFMatrix with appropriate parameters.
 */
class MatrixBuilder {

 public:
  virtual ~MatrixBuilder();

  static shared_ptr<MatrixBuilder> GetInstance();
  // Set width of MTFMatrix
  MatrixBuilder& WithMatrixWidth(int width);
  // Set if random factor should be added (not implemented yet)
  MatrixBuilder& WithRandomAdding();
  // Reset setting of builder to default
  MatrixBuilder& ResetSetting();

  //Generate MTFMatrix
  shared_ptr<MTFMatrix> Generate();

 protected:
  MatrixBuilder();
 private:
  // Width of matrix to build
  int matrix_width_;
  // Remember decision to add random factor
  bool with_random_;
};

} /* namespace Matrix */

#endif /* MATRIXBUILDER_H_ */
