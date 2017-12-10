#include <iostream>
 
using namespace std;
 

template< typename T,bool cond>
struct my_enable_if {};

template <typename T>
struct my_enable_if<T,true>
{
  typedef T type;
};

template <typename T>o
struct is_int{
const static bool val = false;
};

template <>
struct is_int<int>
{
 const static bool val = true;
};

template <typename T, typename my_enable_if<T,!(is_int<T>::val)>::type* = nullptr>
void process(T a)
{
    cout <<  "Processing non - int...\n";
};



template <typename T, typename my_enable_if<T,is_int<T>::val>::type* =nullptr>
void process(T a)
{
    cout <<  "Processing int...\n";
};

int main() {
    
    float f = 5.0;
    process(4.4);
    process(f);
    
    
    return 0;
}
