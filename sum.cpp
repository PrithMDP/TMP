#include <iostream>

using std::cout;
using std::endl;

// A simple templated sum
// TO DO :: error message for empty args -> my_sum::sum<int> -> error!
namespace my_sum{
    
template<typename T,T first, T... other>
struct sum_impl{
const static int value = first + sum_impl<T,other...>::value;
};

template<typename T,T first>
struct sum_impl<T,first>
{
const static int value = first;
};


template <typename T,T... els>
struct sum{
const static int value = sum_impl<T,els...>::value;

};
    


}//my_sum

int main()
{
  static_assert((my_sum::sum<int,1,2,3,-1,43>::value == 48),"oops");
  cout << my_sum::sum<int,1,2,3,-1,43>::value << endl;
}
