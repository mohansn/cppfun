#include <boost/optional.hpp>
#include <boost/config.hpp>
#include <algorithm>

#if BOOST_CXX_VERSION < 201103L
#error "C++ 11 or later is needed for use of Find/Find_if"
#endif

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



