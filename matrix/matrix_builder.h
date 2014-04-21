#ifndef MATRIXBUILDER_H_
#define MATRIXBUILDER_H_

#include <memory>

#include "mtf_matrix.h"
#include "../headers/elements.h"

using std::shared_ptr;

namespace Matrix {

/**
 * Builder of MTFMatrix with appropriate parameters.
 */
class MatrixBuilder {

 public:
  /**
   * Empty destructor, nothing to handle
   */
  virtual ~MatrixBuilder();

  /**
   * Static method to get instance of builder with default
   * set of settings
   * @return Pointer to fresh instance MatrixBuilder
   */
  static shared_ptr<MatrixBuilder> GetInstance();

  /**
   * Method sets width of row in MTFMatrix to generate
   * @param width Width of MTFMatrixs row
   * @return Reference to MatrixBuilder with changed settings
   */
  MatrixBuilder& WithMatrixWidth(int width);

  /**
   * Sets setting of builder to defaults (the same as after GetInstance method)
   * @return Reference to MatrixBuilder with default settings
   */
  MatrixBuilder& ResetSetting();

  /**
   * Generates MTFMatrix using MatrixBuilder configuration
   * @return Pointer to new instance of MTFMatrix
   */
  shared_ptr<MTFMatrix> Generate();

 protected:
  /**
   * Constructor is protected to use static GetInstance method
   */
  MatrixBuilder();

 private:
  int matrix_width_; /**<  Saves WithMatrixWidth function argument. Part of
                           configuration for MTXMatrix creation             */
};

} /* namespace Matrix */

#endif /* MATRIXBUILDER_H_ */
