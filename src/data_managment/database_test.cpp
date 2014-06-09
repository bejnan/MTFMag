/*
 * Base::Database_test.cpp
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

//Check if simple add to Base::Database works
BOOST_AUTO_TEST_CASE(AddToBase) {
  Algorithms::Algorithm* algorithm = new Algorithms::MoveToFront(
      Base::SimpleElement::GetPrototype());
  Tools::Judge* judge = new Tools::Tester(20, 20);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(algorithm);
  shared_ptr<Tools::Judge> judge_ptr(judge);
  Tools::ProcessorFactory tree_factory(algorithm_ptr, judge_ptr);

  shared_ptr<Tools::Processor> processor_ptr = tree_factory.GenerateProcessor(
      1);
  Base::Database::GetInstance().AddToBase(processor_ptr);

  BOOST_CHECK_EQUAL(Base::Database::GetInstance().Query(1).front(),
                    processor_ptr);
  Base::Database::GetInstance().ClearDatabase();
}

//Check if exceptions works
BOOST_AUTO_TEST_CASE(AddToBaseControl) {
  BOOST_CHECK_THROW(Base::Database::GetInstance().Query(3),
                    Exception::InvalidIndexException);
  BOOST_CHECK_THROW(Base::Database::GetInstance().Query("Tester"),
                    Exception::InvalidNameException);
  Base::Database::GetInstance().ClearDatabase();
}

//Check if Exists works
BOOST_AUTO_TEST_CASE(ExistFalse) {
  BOOST_CHECK_EQUAL(Base::Database::GetInstance().Exists(1), false);
  Base::Database::GetInstance().ClearDatabase();
}

//Check if Exists works (harder test)
BOOST_AUTO_TEST_CASE(Exist2) {
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
  Base::Database::GetInstance().AddToBase(processor_ptr);
  BOOST_CHECK_EQUAL(Base::Database::GetInstance().Exists(1), true);

  processor_ptr = mtf_factory.GenerateProcessor(1);
  Base::Database::GetInstance().AddToBase(processor_ptr);
  BOOST_CHECK_EQUAL(Base::Database::GetInstance().Exists(1), true);
  BOOST_CHECK_EQUAL(Base::Database::GetInstance().Exists(2), false);
  Base::Database::GetInstance().ClearDatabase();
}

//Check QueryKeys method
BOOST_AUTO_TEST_CASE(QueryKeys) {
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
  // list of elements returned by Base::Database object
  vector<string> queried_processors;

  shared_ptr<Tools::Processor> processor_ptr = tree_factory.GenerateProcessor(
      1);
  Base::Database::GetInstance().AddToBase(processor_ptr);
  expected_processors.push_front(processor_ptr->AlgorithmName());

  processor_ptr = mtf_factory.GenerateProcessor(1);
  Base::Database::GetInstance().AddToBase(processor_ptr);
  expected_processors.push_front(processor_ptr->AlgorithmName());

  queried_processors = Base::Database::GetInstance().QueryAlgorithmNames();

  BOOST_CHECK_EQUAL_COLLECTIONS(expected_processors.begin(),
                                expected_processors.end(),
                                queried_processors.begin(),
                                queried_processors.end());
  Base::Database::GetInstance().ClearDatabase();
}

//Check QueryKeys method (more complex example)
BOOST_AUTO_TEST_CASE(QueryKeys2) {
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
  Base::Database::GetInstance().AddToBase(processor_ptr);
  expected_processors.push_front(processor_ptr->AlgorithmName());

  processor_ptr = mtf_factory.GenerateProcessor(1);
  Base::Database::GetInstance().AddToBase(processor_ptr);
  expected_processors.push_front(processor_ptr->AlgorithmName());

  processor_ptr = mtf_factory.GenerateProcessor(2);
  Base::Database::GetInstance().AddToBase(processor_ptr);

  processor_ptr = tree_factory.GenerateProcessor(2);
  Base::Database::GetInstance().AddToBase(processor_ptr);

  queried_processors = Base::Database::GetInstance().QueryAlgorithmNames();

  BOOST_CHECK_EQUAL_COLLECTIONS(expected_processors.begin(),
                                expected_processors.end(),
                                queried_processors.begin(),
                                queried_processors.end());
  Base::Database::GetInstance().ClearDatabase();
}

// Test Query method (by id)
BOOST_AUTO_TEST_CASE(QueryById) {
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
  Base::Database::GetInstance().AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  processor_ptr = mtf_factory.GenerateProcessor(1);
  Base::Database::GetInstance().AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  processor_ptr = matrix_factory.GenerateProcessor(1);
  Base::Database::GetInstance().AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  processor_ptr = random_tree_factory.GenerateProcessor(1);
  Base::Database::GetInstance().AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  queried_processors = Base::Database::GetInstance().Query(1);
  BOOST_CHECK_EQUAL_COLLECTIONS(expected_processors.begin(),
                                expected_processors.end(),
                                queried_processors.begin(),
                                queried_processors.end());
  Base::Database::GetInstance().ClearDatabase();
}

//Test Query method (by string)
BOOST_AUTO_TEST_CASE(QueryByName) {
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
  Base::Database::GetInstance().AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  processor_ptr = tree_factory.GenerateProcessor(2);
  Base::Database::GetInstance().AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  processor_ptr = tree_factory.GenerateProcessor(3);
  Base::Database::GetInstance().AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  processor_ptr = tree_factory.GenerateProcessor(4);
  Base::Database::GetInstance().AddToBase(processor_ptr);
  expected_processors.push_back(processor_ptr);

  queried_processors = Base::Database::GetInstance().Query("TreeMTF");
  BOOST_CHECK_EQUAL_COLLECTIONS(expected_processors.begin(),
                                expected_processors.end(),
                                queried_processors.begin(),
                                queried_processors.end());
  Base::Database::GetInstance().ClearDatabase();
}

BOOST_AUTO_TEST_SUITE_END()
