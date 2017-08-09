/**
 * Test fixtures are useful for setting up and managing test context 
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test Module by Ang

#include <boost/test/unit_test.hpp>



struct F {
    F() : i( 0 ) { BOOST_TEST_MESSAGE( "==> setup fixture" ); }
    ~F()         { BOOST_TEST_MESSAGE( "==> teardown fixture" ); }

    int i;
};

/** 
 * You can use test fixture by specifying test cases separately, or group them in test suites
 * Uncomment USE_TEST_SUITE to see the test_suite example 
*/
# define USE_TEST_SUITE


#if defined(USE_TEST_SUITE)

// With fixture, the struct becomes the test context

BOOST_FIXTURE_TEST_CASE( test_case1, F )
{
    BOOST_CHECK( i == 1 );
    ++i;
}

BOOST_FIXTURE_TEST_CASE( test_case2, F )
{
    BOOST_CHECK_EQUAL( i, 1 );
}

// Without fixture, you need to manage the struct

BOOST_AUTO_TEST_CASE( test_case3 )
{
    F myFixture;
    BOOST_CHECK( myFixture.i == 1 );
}

#else

// Using fixture test suite relieves you from specifying the fixture for every test case

BOOST_FIXTURE_TEST_SUITE( test_suite1, F )

BOOST_AUTO_TEST_CASE( test_case1 )
{
    BOOST_CHECK( i == 1 );
    ++i;
}

BOOST_AUTO_TEST_CASE( test_case2 )
{
    BOOST_CHECK_EQUAL( i, 1 );
}

BOOST_AUTO_TEST_SUITE_END()
#endif