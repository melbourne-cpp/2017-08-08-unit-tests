/**
 * User defined types
 */

#include <iostream>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test Module by Ang

#include <boost/test/unit_test.hpp>


/**
 * For user defined types, you need to overload the functions used in your test (EQUAL, GT, LT, etc)
 * If you want to show the value, you need to provide an stream output function 
 */
namespace noo
{
	template <typename T>
	struct Point2D
	{
	  Point2D(T x, T y):_x(x),_y(y) {}
	  T _x;
	  T _y;	  
	};
}


/**
 * overloading needs to be within the same namespace
 */
namespace noo
{
	template <typename T>
	bool operator==(const Point2D<T>& p1,const Point2D<T>& p2)
	{
		return (p1._x==p2._x && p1._y==p2._y);
	}

	template <typename T>
	std::ostream& operator<<(std::ostream& os, const Point2D<T>& p)
	{
		return os << "**{" << p._x << ", " << p._y << "}**#@@#^#$&";
	}
}

BOOST_AUTO_TEST_CASE(user_defined_types)
{

	using namespace noo;
    // user defined type
    Point2D<float> p1{1,1};
    BOOST_CHECK_EQUAL(p1, Point2D<float>(1,0.9)); // relies on the operator==
    // BOOST_CHECK_EQUAL(p1, Point2D<float>(1,0.9999999)); // relies on the operator==
}
