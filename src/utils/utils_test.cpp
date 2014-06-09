#include "utils.h"


#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(UtilsTest)

BOOST_AUTO_TEST_CASE(ToStringFromInt) {
  BOOST_CHECK_EQUAL("1001", Utils::ToString(1001));
}

BOOST_AUTO_TEST_CASE(ToStringFromDouble) {
  BOOST_CHECK_EQUAL("100", Utils::ToString(100));
}

BOOST_AUTO_TEST_CASE(ToStringFromDouble2) {
  BOOST_CHECK_EQUAL("100.02", Utils::ToString(100.02345));
}

BOOST_AUTO_TEST_SUITE_END()
