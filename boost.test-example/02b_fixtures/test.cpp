/**
 * Global Test fixtures  
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test Module by Ang

#include <boost/test/unit_test.hpp>

// Global fixture
struct GF {
    GF() { 
    	BOOST_TEST_MESSAGE( "==> setup global fixture" ); 
    	BOOST_TEST_MESSAGE( "==> gain access to some expensive resource" ); 
    }
    ~GF() { 
    	BOOST_TEST_MESSAGE( "==> teardown global fixture" ); 
    	BOOST_TEST_MESSAGE( "==> free expensive resource" ); 
    }

    static int i;
};
int GF::i = 0;

// test suite fixture
struct F {
    F() : i_ref( GF::i ) { 
    	BOOST_TEST_MESSAGE( "==> setup fixture" ); 
    }
    ~F()         { 
    	BOOST_TEST_MESSAGE( "==> teardown fixture" ); 
    }

    int &i_ref;
};

/**
 * When multiple tests require access to an expensive resource (file, connection, database, etc)
 * we can use the global fixture. However, test cannot access global fixture directly, so some
 * other means may be required.
 */

BOOST_GLOBAL_FIXTURE(GF);

BOOST_FIXTURE_TEST_SUITE( test_suite1, F )

BOOST_AUTO_TEST_CASE( test_case1 )
{
    BOOST_CHECK( i_ref == 1 );
    // ++i; // no direct access to global fixture
    ++i_ref; // ok
}

BOOST_AUTO_TEST_CASE( test_case2 )
{
    BOOST_CHECK_EQUAL( i_ref, 1 );
}

BOOST_AUTO_TEST_SUITE_END()