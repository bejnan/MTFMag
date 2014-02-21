/*
 * Database_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "Database.h"
#include "../Headers/Tools.h"
#include "../Headers/Exceptions.h"

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <memory>

using std::shared_ptr;

bool always_true() {
  return true;
}

BOOST_AUTO_TEST_SUITE(Database)

BOOST_AUTO_TEST_CASE(AddToBase) {
  Base::Database base;
  Tools::Processor* new_processor = new Tools::Processor(1, "Test");
  shared_ptr<Tools::Processor> processor_ptr(new_processor);
  base.AddToBase(processor_ptr);

  BOOST_CHECK_EQUAL(base.Query(1).front(), processor_ptr);

  new_processor = new Tools::Processor(2, "Test2");
  processor_ptr.reset(new_processor);
  base.AddToBase(processor_ptr);

  BOOST_CHECK_EQUAL(base.Query("Test2").front(), processor_ptr);

  BOOST_CHECK_THROW(base.Query(3), Exception::InvalidIndexException);

  BOOST_CHECK_THROW(base.Query("Tester"), Exception::InvalidNameException);



}

BOOST_AUTO_TEST_SUITE_END()
