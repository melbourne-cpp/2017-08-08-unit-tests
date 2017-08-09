/**
 * Predicates
 */

#include <iostream>
#include <vector>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test Module by Ang

#include <boost/test/unit_test.hpp>



/**
 * Predicates allow you to see the values of your parameters
 */

// bool sum_is_even(int a, int b)
// {
//   return !((a+b)%2);
// }

// BOOST_AUTO_TEST_CASE( normal_test )
// {
//   int a = 2;
//   int b = 3;
//   BOOST_CHECK( sum_is_even( a,b ) );
// }

// BOOST_AUTO_TEST_CASE( predicate_test )
// {
//   int a = 2;
//   int b = 3;
//   BOOST_CHECK_PREDICATE( sum_is_even, (a)(b) ); // shows the argument values
// }



/**
 * For parameters of more complex types, you need to define stream output
 */

bool sum_is_even_v(std::vector<int> v)
{
  int sum = 0;
  std::for_each(v.begin(),v.end(),[&](int &n){ sum+=n; });
  return !((sum)%2);
}

// Need to define in vector's namespace 
namespace std
{
  template <typename T>
  std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
  {
      os << '[';
      std::copy (v.begin(), v.end(), std::ostream_iterator<T>(os, ", "));
      os << "\b\b]";
    return os;
  }
}

BOOST_AUTO_TEST_CASE( predicate_complex_types )
{
  std::vector<int> v{1,2,3,4,5};
  BOOST_CHECK_PREDICATE( sum_is_even_v, (v) ); // fail
}

