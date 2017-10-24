// Example program
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <deque>

using namespace std;

template <typename T>
struct WhichType;

// ++ wont persist cause tp is being passed by value
// how do I forward it? I have tried a few things but I am
// not sure what the exact variadic template forward syntax is

template<size_t N,typename... Args>
struct visit
{
    static void print(tuple<Args...> tp)
    {                
        constexpr int num = N;
        get<num>(tp)++;
        cout << num << " " << get<num>(tp) << endl;
        
        //recursive call
        visit<num-1,Args...>::print(tp);
    }
};

//base case 
template<typename... Args>
struct visit<0,Args...>
{
    static void print(tuple<Args...> tp)
    {
       
        get<0>(tp)++;
        cout << "0" << " " << get<0>(tp) << endl;
    }
};

template <typename... Args>
void visit_wrapper(size_t size,tuple<Args...> tp)
{
    static_cast<void>(size);
    constexpr size_t size_tup = 2;
    visit<size_tup,Args...>::print(tp);
    
}

int main()
{
    tuple<int,int,int> a{11,2,3};
    
    visit_wrapper(size_t(3),a);
    
    cout << "increment not working cause pass by value? \n";
    
    
    cout << get<0>(a);
    
}
