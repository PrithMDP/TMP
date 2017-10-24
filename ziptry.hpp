// Example program
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <deque>

using namespace std;

template<typename T>
struct WhichType;

template <typename T,typename... Args>
T return_type(T a,Args... junk)
{
    return a;
}


// trying to push_back each args... .begin() into vec with this

template <typename T,typename begin>
void populate_vec(vector<begin>& vec,T&& a)
{
    vec.push_back(a.begin());
    return;
}


template <typename T,typename... Args,typename begin>
void populate_vec(vector<begin>& vec,T&& a, Args&&... args)
{
    vec.push_back(a.begin());
    populate_vec(vec,forward<Args>(args)...);
    
}


template <typename... Args>
void test(Args... args)
{
    //tuple<decltype(declval<T>().begin())> tpl;
    //doing this to just declare the vec
    vector<decltype(return_type(args...).begin())> itrs;
    //vector is now of type vector<int>.begin()    
    
    populate_vec(itrs,args...);
    
    cout << "size: " << itrs.size() << endl;
    
    //now itrs hold begin() for each of the input vectors
    
    for(auto x: itrs)
    {
        cout << *x  << endl;
    }
    
}


int main()
{
    vector<int> vec{99,2,83,99,3};
    vector<int> vec2{2,3,4,5,6};
    
    test(vec,vec2); 
}
