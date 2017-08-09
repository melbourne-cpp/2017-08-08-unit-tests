/**
 * Exceptions
 */

#include <iostream>
#include <vector>
#include <valarray>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test Module by Ang

#include <boost/test/unit_test.hpp>


/**
 * Certain checks where you expect exceptions to throw, or not to throw
 */

class my_exception{};

BOOST_AUTO_TEST_CASE( expected_exceptions )
{
  int i =  0;

  BOOST_CHECK_THROW( i++, my_exception ); // fail
  BOOST_CHECK_THROW( throw std::runtime_error("Expected a different exception."), my_exception ); // fail: unmatched exception
  BOOST_CHECK_THROW( throw my_exception(), my_exception ); // pass
}

BOOST_AUTO_TEST_CASE( unexpected_exceptions )
{
  int i =  0;

  BOOST_CHECK_NO_THROW(i++); // pass
  BOOST_CHECK_NO_THROW(throw std::runtime_error("Did not see this coming.")); // fail
}