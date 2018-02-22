#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <cstdlib>

using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;
using std::void_t;
using std::declval;
using std::enable_if;
using std::enable_if_t;

struct test
{
    int has_data_fn();  
};

template <typename T,typename = void>
struct has_data
{
    const static bool val = false;
};

template <typename T>
struct has_data<T,void_t<decltype(declval<T>().has_data_fn())>>
{
    const static bool val = true;
};



template <typename T>
void print_has_data( T a, typename enable_if<!has_data<T>::val,T>::type* = nullptr)
{
    cout << "no has_data\n";
    static_cast<void>(a);
}


template <typename T, typename enable_if<has_data<T>::val,T>::type* = nullptr>
void print_has_data( T a)
{
    cout << "has_data\n";
    static_cast<void>(a);
}


int main()
{
   
    test f;
    print_has_data(f);
    
    cout <<std::boolalpha<< has_data<test>::val << endl;
}


