/**
 * Timeout (supported by 1.59 onwards)
 * Caution: Timeout not implemented in Windows. Yet.
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test Module by Ang

#include <boost/test/unit_test.hpp>

#include <complex>


/**
 * Tolerance works with BOOST_TEST, but not BOOST_CHECK and other similar MACROS
 * In this test, the right hand side is treated as the reference value. 
 * Note that tolerance will only be applied on values that share the same type used 
 * for specifying tolerance. 
 * For a tolerance of 1%, a test passes if lhs is in the range [rhs-1% rhs+1%]
 */

namespace utf = boost::unit_test;
namespace fpc = boost::test_tools::fpc;

BOOST_AUTO_TEST_CASE(absolute_comparison,* utf::tolerance(0.001f))
{
	// [0.999 1.001]
    BOOST_TEST(0.991f==1.0f);
    BOOST_TEST(0.9991f==1.0f); 
}

BOOST_AUTO_TEST_CASE(percentage_comparison,* utf::tolerance(fpc::percent_tolerance(1.0f))) // 1% tolerance
{
	// [0.99 1.01]
    BOOST_TEST(0.991f==1.0f);
    BOOST_TEST(0.9991f==1.0f);
}
