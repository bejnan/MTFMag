/*
 * Database_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#include "database.h"
#include "../headers/tools.h"
#include "../headers/exceptions.h"
#include "../headers/algorithms.h"

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <memory>
#include <list>

using std::shared_ptr;
using std::list;

BOOST_AUTO_TEST_SUITE(Database)

//Check if simple add to Database works
BOOST_AUTO_TEST_CASE(AddToBase) {
  Base::Database base;
  Algorithms::Algorithm* algorithm = new Algorithms::MoveToFront(
      Base::SimpleElement::GetPrototype());
  Tools::Judge* judge = new Tools::Tester(20, 20);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(algorithm);
  shared_ptr<Tools::Judge> judge_ptr(judge);
  Tools::ProcessorFactory tree_factory(algorithm_ptr, judge_ptr);

  shared_ptr<Tools::Processor> processor_ptr = tree_factory.GenerateProcessor(
      1);
  base.AddToBase(processor_ptr);

  BOOST_CHECK_EQUAL(base.Query(1).front(), processor_ptr);
}

//Check if exceptions works
BOOST_AUTO_TEST_CASE(AddToBaseControl) {
  Base::Database base;
  BOOST_CHECK_THROW(base.Query(3), Exception::InvalidIndexException);
  BOOST_CHECK_THROW(base.Query("Tester"), Exception::InvalidNameException);
}

//Check if Exists works
BOOST_AUTO_TEST_CASE(ExistFalse) {
  Base::Database base;
  BOOST_CHECK_EQUAL(base.Exists(1), false);
}

//Check if Exists works (harder test)
BOOST_AUTO_TEST_CASE(Exist2) {
  Base::Database base;
  Algorithms::Algorithm* algorithm = new Algorithms::TreeRoot(
      Base::SimpleElement::GetPrototype());
  Tools::Judge* judge = new Tools::Tester(20, 20);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(algorithm);
  shared_ptr<Tools::Judge> judge_ptr(judge);
  Tools::ProcessorFactory tree_factory(algorithm_ptr, judge_ptr);

  algorithm = new Algorithms::MoveToFront(Base::SimpleElement::GetPrototype());

  shared_ptr<Algorithms::Algorithm> mtf_algorithm_ptr(algorithm);
  Tools::ProcessorFactory mtf_factory(mtf_algorithm_ptr, judge_ptr);

  shared_ptr<Tools::Processor> processor_ptr = tree_factory.GenerateProcessor(
      1);
  base.AddToBase(processor_ptr);
  BOOST_CHECK_EQUAL(base.Exists(1), true);

  processor_ptr = mtf_factory.GenerateProcessor(1);
  base.AddToBase(processor_ptr);
  BOOST_CHECK_EQUAL(base.Exists(1), true);
  BOOST_CHECK_EQUAL(base.Exists(2), false);

}

//Check QueryKeys method
BOOST_AUTO_TEST_CASE(QueryKeys) {
  Base::Database base;
  Algorithms::Algorithm* algorithm = new Algorithms::TreeRoot(
      Base::SimpleElement::GetPrototype());
  Tools::Judge* judge = new Tools::Tester(20, 20);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(algorithm);
  shared_ptr<Tools::Judge> judge_ptr(judge);
  Tools::ProcessorFactory tree_factory(algorithm_ptr, judge_ptr);

  algorithm = new Algorithms::MoveToFront(Base::SimpleElement::GetPrototype());

  shared_ptr<Algorithms::Algorithm> mtf_algorithm_ptr(algorithm);
  Tools::ProcessorFactory mtf_factory(mtf_algorithm_ptr, judge_ptr);

  // list of expected elements
  list<string> expected_processors;
  // list of elements returned by Database object
  vector<string> queried_processors;

  shared_ptr<Tools::Processor> processor_ptr = tree_factory.GenerateProcessor(
      1);
  base.AddToBase(processor_ptr);
  expected_processors.push_front(processor_ptr->AlgorithmName());

  processor_ptr = mtf_factory.GenerateProcessor(1);
  base.AddToBase(processor_ptr);
  expected_processors.push_front(processor_ptr->AlgorithmName());

  queried_processors = base.QueryAlgorithmNames();

  BOOST_CHECK_EQUAL_COLLECTIONS(expected_processors.begin(),
                                expected_processors.end(),
                                queried_processors.begin(),
                                queried_processors.end());
}

//Check QueryKeys method (more complex example)
BOOST_AUTO_TEST_CASE(QueryKeys2) {
  Base::Database base;
  Algorithms::Algorithm* algorithm = new Algorithms::TreeRoot(
      Base::SimpleElement::GetPrototype());
  Tools::Judge* judge = new Tools::Tester(20, 20);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(algorithm);
  shared_ptr<Tools::Judge> judge_ptr(judge);
  Tools::ProcessorFactory tree_factory(algorithm_ptr, judge_ptr);

  algorithm = new Algorithms::MoveToFront(Base::SimpleElement::GetPrototype());
  shared_ptr<Algorithms::Algorithm> mtf_algorithm_ptr(algorithm);
  Tools::ProcessorFactory mtf_factory(mtf_algorithm_ptr, judge_ptr);

  list<string> expected_processors;
  vector<string> queried_processors;

  shared_ptr<Tools::Processor> processor_ptr = tree_factory.GenerateProcessor(
      1);
  base.AddToBase(processor_ptr);
  expected_processors.push_front(processor_ptr->AlgorithmName());

  processor_ptr = mtf_factory.GenerateProcessor(1);
  base.AddToBase(processor_ptr);
  expected_processors.push_front(processor_ptr->AlgorithmName());

  processor_ptr = mtf_factory.GenerateProcessor(2);
  base.AddToBase(processor_ptr);

  processor_ptr = tree_factory.GenerateProcessor(2);
  base.AddToBase(processor_ptr);

  queried_processors = base.QueryAlgorithmNames();

  BOOST_CHECK_EQUAL_COLLECTIONS(expected_processors.begin(),
                                expected_processors.end(),
                                queried_processors.begin(),
                                queried_processors.end());
}

// Test Query method (by id)
BOOST_AUTO_TEST_CASE(QueryById) {
  Base::Database base;
  Algorithms::Algorithm* algorithm = new Algorithms::TreeRoot(
      Base::SimpleElement::GetPrototype());
  Tools::Judge* judge = new Tools::Tester(20, 20);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(algorithm);
  shared_ptr<Tools::Judge> judge_ptr(judge);
  Tools::ProcessorFactory tree_factory(algorithm_ptr, judge_ptr);

  algorithm = new Algorithms::MoveToFront(Base::SimpleElement::GetPrototype());
  shared_ptr<Algorithms::Algorithm> mtf_algorithm_ptr(algorithm);
  Tools::ProcessorFactory mtf_factory(mtf_algorithm_ptr, judge_ptr);

  algorithm = new Algorithms::MTFMatrix(Base::SimpleElement::GetPrototype());
  shared_ptr<Algorithms::Algorithm> matrix_algorithm_ptr(algorithm);
  Tools::ProcessorFactory matrix_factory(matrix_algorithm_ptr, judge_ptr);

  algorithm = new Algorithms::RandomTreeRoot(
      Base::SimpleElement::GetPrototype());
  shared_ptr<Algorithms::Algorithm> random_tree_algorithm_ptr(algorithm);
  Tools::ProcessorFactory random_tree_factory(random_tree_algorithm_ptr,
                                              judge_ptr);

  list<shared_ptr<Tools::Processor> > expected_processors;
  vector<shared_ptr<Tools::Processor> > queried_processors;

  shared_ptr<Tools::Processor> processor_ptr = tree_factory.GenerateProcessor(
      1);
  base.AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  processor_ptr = mtf_factory.GenerateProcessor(1);
  base.AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  processor_ptr = matrix_factory.GenerateProcessor(1);
  base.AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  processor_ptr = random_tree_factory.GenerateProcessor(1);
  base.AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  queried_processors = base.Query(1);
  BOOST_CHECK_EQUAL_COLLECTIONS(expected_processors.begin(),
                                expected_processors.end(),
                                queried_processors.begin(),
                                queried_processors.end());
}

//Test Query method (by string)
BOOST_AUTO_TEST_CASE(QueryByName) {
  Base::Database base;
  Algorithms::Algorithm* algorithm = new Algorithms::TreeRoot(
      Base::SimpleElement::GetPrototype());
  Tools::Judge* judge = new Tools::Tester(20, 20);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(algorithm);
  shared_ptr<Tools::Judge> judge_ptr(judge);
  Tools::ProcessorFactory tree_factory(algorithm_ptr, judge_ptr);

  list<shared_ptr<Tools::Processor> > expected_processors;
  vector<shared_ptr<Tools::Processor> > queried_processors;

  shared_ptr<Tools::Processor> processor_ptr = tree_factory.GenerateProcessor(
      1);
  base.AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  processor_ptr = tree_factory.GenerateProcessor(2);
  base.AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  processor_ptr = tree_factory.GenerateProcessor(3);
  base.AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  processor_ptr = tree_factory.GenerateProcessor(4);
  base.AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  queried_processors = base.Query("TreeMTF");
  BOOST_CHECK_EQUAL_COLLECTIONS(expected_processors.begin(),
                                expected_processors.end(),
                                queried_processors.begin(),
                                queried_processors.end());
}

BOOST_AUTO_TEST_SUITE_END()
