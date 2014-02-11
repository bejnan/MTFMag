/*
 * main_test.cpp
 *
 *  Created on: 16 gru 2013
 *      Author: kuba
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include <boost/test/unit_test.hpp>
#include<memory>

using namespace std;

BOOST_AUTO_TEST_SUITE(mainSuite)

BOOST_AUTO_TEST_CASE(True_test)
{
	BOOST_CHECK(1<2);
}

BOOST_AUTO_TEST_SUITE_END()


