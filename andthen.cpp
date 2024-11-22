#include <boost/optional.hpp>
#include <algorithm>
#include <vector>
#include <iostream>


template <typename Iter, typename Value>
auto Find(Iter b, Iter e, Value&& value) -> boost::optional<decltype(*b)>
{
    typedef decltype(*b) value_type;
    boost::optional<value_type> optional_value;
    auto it = std::find(b, e, std::forward<Value>(value));
    if (it != e)
    {
	optional_value = *it;
    }
    return optional_value;
}

template <typename Pred, typename Iter>
auto Find_if(Iter b, Iter e, Pred&& pred) -> boost::optional<decltype(*b)>
{
    typedef decltype(*b) value_type;
    boost::optional<value_type> optional_value;
    auto it = std::find_if(b, e, std::forward<Pred>(pred));
    if (it != e)
    {
	optional_value = *it;
    }
    return optional_value;
}


int process_int(int n)
{
	return n * 10;
}

int main ()
{
	auto print = [](int n) { return 0; };
	std::vector<int> v {1,2,4,5};
	auto r = Find_if(begin(v), end(v), [](int n) { return n % 2 == 0; });
	std::cout << r.map(process_int).value_or(12345) << std::endl;
	std::cout << r.map(print).value_or(12345) << std::endl;
	std::cout << "\n################################" << std::endl;
	auto r2 = Find(begin(v), end(v), 0);
	std::cout << r2.map(print).value_or(12345) << std::endl;
	return 0; 
}

