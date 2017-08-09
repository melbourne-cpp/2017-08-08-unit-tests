/**
 * Timeout (supported by 1.59 onwards)
 * Caution: Timeout not implemented in Windows. Yet.
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test Module by Ang

#include<thread>
#include <boost/test/unit_test.hpp>


/**
 * Timeout lets you abort the test if it takes longer than expected 
 * 
 */

void foo(int n)
{
  std::this_thread::sleep_for(std::chrono::seconds(n));
}

// testing time: 4979099us
BOOST_AUTO_TEST_CASE(timeout0,* boost::unit_test::timeout(5)) // 5 sec timeout
{   
  for (;;){}
}

// testing time: 990995us
BOOST_AUTO_TEST_CASE(timeout1,* boost::unit_test::timeout(1)) // 1 sec timeout
{   
  for (;;){}
}

// testing time: 287us (does it detect the thread sleeping?)
BOOST_AUTO_TEST_CASE(timeout2,* boost::unit_test::timeout(1)) // 1 sec timeout
{   
  foo(1);
}

// testing time: 161us
BOOST_AUTO_TEST_CASE(timeout3,* boost::unit_test::timeout(1)) // 1 sec timeout
{   
  foo(0);
}
