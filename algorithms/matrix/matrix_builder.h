#ifndef MATRIXBUILDER_H_
#define MATRIXBUILDER_H_

#include <memory>

#include "mtf_matrix.h"
#include "../../headers/elements.h"

using std::shared_ptr;

namespace Algorithms {

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
   * Sets prototype for MTFMatrix instance to
   * generate new elements
   * @param element_prototype Pointer to instance of
   * Element class (or it's child class)
   * @return Reference to MatrixBuilder with changed settings
   */
  MatrixBuilder& SetElementPrototype(
      shared_ptr<Base::Element> element_prototype) {
    element_prototype_ = element_prototype;
    return *this;
  }

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
  /** Saves WithMatrixWidth function argument. Part of
   configuration for MTXMatrix creation */
  int matrix_width_;

  /** prototype for MTFMatrix to create new elements */
  shared_ptr<Base::Element> element_prototype_;
};

} /* namespace Matrix */

#endif /* MATRIXBUILDER_H_ */
