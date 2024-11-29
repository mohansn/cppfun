/*
	build command:
	g++ --std=c++14 -I$(BOOST_ROOT)/include -I$(path_to_gtest) test.cpp -o test
*/


// TODO: get this comparison working
#if 0
#if BOOST_CXX_VERSION < 201402L
#warning "C++ 14 or later is needed for use of GoogleTest"
#endif
#endif


#include "gtest/gtest.h"

#include "../AndThen.h"

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int process_int(int n)
{
	return n * 10;
}


TEST(AndThen, Test_free_function)
{
	vector<int> v {1,2,4,5};

	/**
		r is of type boost::optional<int>
		if find_if() returns nothing, r is boost::none,
		else it is a boost::optional<int> contains the value
	*/
	auto r = Find_if(begin(v), end(v), [](int n) { return n % 2 == 0; });
	EXPECT_EQ(r.map(process_int).value_or(12345), 20);
}

TEST(AndThen, Test_lambda_Find_if)
{
	auto print = [](int n) { return 0; };
	vector<int> v {1,2,4,5};
	auto r = Find_if(begin(v), end(v), [](int n) { return n % 2 == 0; });
	EXPECT_EQ(r.map(print).value_or(12345), 0);
}

TEST(AndThen, Test_lambda_Find)
{
	auto print = [](int n) { return 0; };
	vector<int> v {1,2,4,5};
	auto r = Find(begin(v), end(v), 0);
	EXPECT_EQ(r.map(print).value_or(12345), 12345);
}


TEST(AndThen, Test_custom_lambda)
{
	vector<int> v {1,2,4,5};
	EXPECT_EQ(
	Find_if(begin(v), end(v),
		[](int n) { return n > 0; }
	       ).map(
			/* Add your own lambda to run any operation on the value found */
			[] (int n) {
				cout << n << endl;	// for example
			/*
				unfortunately, we need this
				because boost internally needs a reference of type T& where
				T is the return type of the function passed to map().
				Hence, void return is not possible.
			*/
			return 0;
		   }).value_or(12345),
	0);

}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

