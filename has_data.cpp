#include <tuple>
#include <iostream>
#include <array>
#include <utility>
#include <vector>

// simple wrapper to check if passed in object contains a data() method
// inspired by Abseils C++ span.h


using std::cout;
using std::endl;

template <typename T,typename = void>
struct has_data
{
    static const int val = 0;
};

template <typename T>
struct has_data<T,std::void_t<decltype(std::declval<T>().data())>>
{
    static const int val = 1;
};

template <typename T>
void func(T a)
{
    cout << has_data<T>::val << endl;
}
int main()
{
    cout << has_data<int>::val << endl;
    cout << has_data<std::vector<int>>::val << endl;
    
    std::vector<int> a;
    func(a);
}
