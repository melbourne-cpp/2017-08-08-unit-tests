/**
 * Example of simple UTF setup
 * To filter test results:
 * --log_level=all, warning, success, test_suite 
 * (See link: http://www.boost.org/doc/libs/1_63_0/libs/test/doc/html/boost_test/utf_reference/rt_param_reference/log_level.html)
 */


/** 
 * Defines should be placed before including Boost UTF
 */ 
// if using dynamic linking
#define BOOST_TEST_DYN_LINK
// if using static linking (generates default main) 
// #define BOOST_TEST_MAIN

// define name of test module (opt for dyn linking)
#define BOOST_TEST_MODULE Test Module by Ang

#include <boost/test/unit_test.hpp>



/**
 * Test suites helps organise test cases, and can be nested 
 */
BOOST_AUTO_TEST_SUITE(assertions_suite) 

BOOST_AUTO_TEST_SUITE(assertions_suite_lvl2) 

BOOST_AUTO_TEST_CASE(assertions)
{   
    BOOST_WARN(2+2==4); // warning
    BOOST_CHECK(2+2==4); // will proceed despite fail
    BOOST_REQUIRE(2+2==4); // cannot proceed if fail
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(assertions_test_level)
{  
  /** 
   * Some checks are expected to fail, but UTF provides test levels that 
   * allow you to continue despite fails. 
   */
    BOOST_WARN(2+2==1); // warning
    BOOST_CHECK(2+2==1); // will proceed despite fail
    BOOST_REQUIRE(2+2==1); // cannot proceed if fail
    BOOST_CHECK(1 != 1); // error - will never reach here
}
BOOST_AUTO_TEST_SUITE_END()
 
