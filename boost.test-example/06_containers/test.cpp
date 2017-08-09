/**
 * Container Test  
 */

#include <iostream>
#include <vector>
#include <valarray>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test Module by Ang

#include <boost/test/unit_test.hpp>



/**
 * Using valarray and vector
 */

BOOST_AUTO_TEST_CASE(containers_valarray)
{
    std::valarray<double> in{ 1,2,3,4 };
    std::valarray<double> expected{ 1,4,9,16 };

    in*=in; //square element-wise
    
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(in),std::end(in),std::begin(expected),std::end(expected)); 
}


// You may want to define a macro to simplify the syntax
#define CHECK_EQUAL_CONTAINERS(left_, right_) \
    BOOST_CHECK_EQUAL_COLLECTIONS(left_.begin(), left_.end(), right_.begin(), right_.end())


BOOST_AUTO_TEST_CASE(containers_vectors)
{
    std::vector<double> in{ 1,2,3,4 };
    std::vector<double> expected{ 1,4,9,16 };

    // std::for_each(in.begin(), in.end(), [](double &n){ n=n*n; });

    CHECK_EQUAL_CONTAINERS(in,expected);
    // BOOST_CHECK_EQUAL_COLLECTIONS(in.begin(),in.end(),expected.begin(),expected.end()); 

}
