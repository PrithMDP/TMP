#include <iostream>

using std::cout;
using std::endl;

namespace my_min
{
template <typename T, T first, T... rest>
struct min_impl
{
    const static T min_val = first < min_impl<T,rest...>::min_val ? first: min_impl<T,rest...>::min_val;
};
    
template <typename T, T first, T second>
struct min_impl<T,first,second>
{
   const static T min_val = first < second ? first : second;
};
    
    
template <typename T,T... rest>
struct min
{
    const static T min_val = min_impl<T,rest...>::min_val;
};
    
    
} // namespace min_impl

int main()
{
    cout << my_min::min_impl<int,2,3,1,-1,-99>::min_val;
}
