#include "AndThen.h"

#include <vector>
#include <iostream>

int process_int(int n)
{
	return n * 10;
}

int main ()
{
	auto print = [](int n) { return 0; };
	std::vector<int> v {1,2,4,5};

	/**
		r is of type boost::optional<int>
		if find_if() returns nothing, r is boost::none,
		else it is a boost::optional<int> contains the value
	*/
	auto r = Find_if(begin(v), end(v), [](int n) { return n % 2 == 0; });

	std::cout << r.map(process_int)
		      .value_or(12345)
		  << std::endl;

	std::cout << r.map(print).value_or(12345) << std::endl;

	std::cout << "\n################################" << std::endl;
	auto r2 = Find(begin(v), end(v), 0);
	std::cout << r2.map(print).value_or(12345) << std::endl;
	return 0; 
}

