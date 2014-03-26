/*
 * Database_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "database.h"
#include "../headers/tools.h"
#include "../headers/exceptions.h"

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <memory>
#include <list>

using std::shared_ptr;
using std::list;

BOOST_AUTO_TEST_SUITE(Database)

BOOST_AUTO_TEST_CASE(AddToBase) {
  Base::Database base;
  Tools::TreeProcessorFactory factory;
  Tools::MTFProcessorFactory mtf_factory;

  shared_ptr<Tools::Processor> processor_ptr = factory.GenerateProcessor(1);
  base.AddToBase(processor_ptr);

  BOOST_CHECK_EQUAL(base.Query(1).front(), processor_ptr);

  processor_ptr = mtf_factory.GenerateProcessor(2);
  base.AddToBase(processor_ptr);

  BOOST_CHECK_EQUAL(base.Query("SimpleMTF").front(), processor_ptr);

  BOOST_CHECK_THROW(base.Query(3), Exception::InvalidIndexException);

  BOOST_CHECK_THROW(base.Query("Tester"), Exception::InvalidNameException);

}

BOOST_AUTO_TEST_CASE(Exist) {
  Base::Database base;
  Tools::TreeProcessorFactory factory;
  Tools::MTFProcessorFactory mtf_factory;

  BOOST_CHECK_EQUAL(base.Exists(1), false);

  shared_ptr<Tools::Processor> processor_ptr = factory.GenerateProcessor(1);
  base.AddToBase(processor_ptr);
  BOOST_CHECK_EQUAL(base.Exists(1), true);
  processor_ptr = mtf_factory.GenerateProcessor(1);
  base.AddToBase(processor_ptr);
  BOOST_CHECK_EQUAL(base.Exists(1), true);
  BOOST_CHECK_EQUAL(base.Exists(2), false);

}

BOOST_AUTO_TEST_CASE(QueryKeys) {
  Base::Database base;
  Tools::TreeProcessorFactory factory;
  Tools::MTFProcessorFactory mtf_factory;
  list<string> expected_processors;
  vector<string> queried_processors;

  shared_ptr<Tools::Processor> processor_ptr = factory.GenerateProcessor(1);
  base.AddToBase(processor_ptr);
  expected_processors.push_front(processor_ptr->identifier());

  processor_ptr = mtf_factory.GenerateProcessor(1);
  base.AddToBase(processor_ptr);
  expected_processors.push_front(processor_ptr->identifier());

  queried_processors = base.QueryKeys();

  BOOST_CHECK_EQUAL_COLLECTIONS(expected_processors.begin(),
                                expected_processors.end(),
                                queried_processors.begin(),
                                queried_processors.end());
}

BOOST_AUTO_TEST_CASE(QueryKeys2) {
  Base::Database base;
  Tools::TreeProcessorFactory factory;
  Tools::MTFProcessorFactory mtf_factory;
  list<string> expected_processors;
  vector<string> queried_processors;

  shared_ptr<Tools::Processor> processor_ptr = factory.GenerateProcessor(1);
  base.AddToBase(processor_ptr);
  expected_processors.push_front(processor_ptr->identifier());

  processor_ptr = mtf_factory.GenerateProcessor(1);
  base.AddToBase(processor_ptr);
  expected_processors.push_front(processor_ptr->identifier());

  processor_ptr = mtf_factory.GenerateProcessor(2);
  base.AddToBase(processor_ptr);

  processor_ptr = factory.GenerateProcessor(2);
  base.AddToBase(processor_ptr);

  queried_processors = base.QueryKeys();

  BOOST_CHECK_EQUAL_COLLECTIONS(expected_processors.begin(),
                                expected_processors.end(),
                                queried_processors.begin(),
                                queried_processors.end());
}

BOOST_AUTO_TEST_SUITE_END()
