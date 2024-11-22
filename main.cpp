#include "AndThen.h"

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int process_int(int n)
{
	return n * 10;
}

int main ()
{
	auto print = [](int n) { return 0; };
	vector<int> v {1,2,4,5};

	/**
		r is of type boost::optional<int>
		if find_if() returns nothing, r is boost::none,
		else it is a boost::optional<int> contains the value
	*/
	auto r = Find_if(begin(v), end(v), [](int n) { return n % 2 == 0; });
	cout << r.map(process_int)
		      .value_or(12345)
		  << endl;

	cout << "\n################################" << endl;
	cout << r.map(print).value_or(12345) << endl;

	cout << "\n################################" << endl;
	auto r2 = Find(begin(v), end(v), 0);
	cout << r2.map(print).value_or(12345) << endl;

	cout << "\n################################" << endl;
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
				   });
	return 0; 
}

