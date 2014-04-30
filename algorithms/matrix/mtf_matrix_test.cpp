#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "matrix_builder.h"
#include "mtf_matrix.h"

using Algorithms::MatrixBuilder;
using Algorithms::MTFMatrix;

BOOST_AUTO_TEST_SUITE(MTFMatrix_Test)

//check correctness of adding elements to MTFMatrix
BOOST_AUTO_TEST_CASE(AddingElement) {
  //initialization
  shared_ptr<MatrixBuilder> builder = MatrixBuilder::GetInstance();
  shared_ptr<MTFMatrix> matrix = builder->WithMatrixWidth(2).Generate();
  shared_ptr<Base::Element> element;
  for (int i = 1; i < 6; i++) {
    matrix->AddElement(i);
  }

  //check element order
  for (int i = 1; i < 6; i++) {
    BOOST_CHECK_EQUAL(i, matrix->GetContentPosition(i));
  }
}

//check correctness of adding elements to MTFMatrix with simple notification
BOOST_AUTO_TEST_CASE(MTFMatrixNotifiaction) {
  //initialization
  shared_ptr<MatrixBuilder> builder = MatrixBuilder::GetInstance();
  shared_ptr<MTFMatrix> matrix = builder->WithMatrixWidth(2).Generate();

  shared_ptr<Base::Element> element;
  for (int i = 1; i < 6; i++) {
    matrix->AddElement(i);
  }

  matrix->NotifyContent(2);
  BOOST_CHECK_EQUAL(1, matrix->GetContentPosition(2));
  BOOST_CHECK_EQUAL(2, matrix->GetContentPosition(1));
  BOOST_CHECK_EQUAL(3, matrix->GetContentPosition(3));
  BOOST_CHECK_EQUAL(4, matrix->GetContentPosition(4));
  BOOST_CHECK_EQUAL(5, matrix->GetContentPosition(5));
}

BOOST_AUTO_TEST_CASE(MTFMatrixTwoNotifiactions) {
  //initialization
  shared_ptr<MatrixBuilder> builder = MatrixBuilder::GetInstance();
  shared_ptr<MTFMatrix> matrix = builder->WithMatrixWidth(2).Generate();

  shared_ptr<Base::Element> element;
  for (int i = 1; i < 6; i++) {
    matrix->AddElement(i);
  }

  matrix->NotifyContent(2);
  BOOST_CHECK_EQUAL(1, matrix->GetContentPosition(2));
  BOOST_CHECK_EQUAL(2, matrix->GetContentPosition(1));
  BOOST_CHECK_EQUAL(3, matrix->GetContentPosition(3));
  BOOST_CHECK_EQUAL(4, matrix->GetContentPosition(4));
  BOOST_CHECK_EQUAL(5, matrix->GetContentPosition(5));

  // last element become first
  matrix->NotifyContent(5);
  BOOST_CHECK_EQUAL(1, matrix->GetContentPosition(5));
  BOOST_CHECK_EQUAL(2, matrix->GetContentPosition(1));
  BOOST_CHECK_EQUAL(3, matrix->GetContentPosition(2));
  BOOST_CHECK_EQUAL(4, matrix->GetContentPosition(4));
  BOOST_CHECK_EQUAL(5, matrix->GetContentPosition(3));

}

BOOST_AUTO_TEST_SUITE_END()
