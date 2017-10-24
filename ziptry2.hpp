// Example program
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <deque>

using namespace std;



//how to forward the vector/deque?

/* i am trying 2 make 2 tuples one with .begin() for each of the containers
   other with .end() for the same containers.
   
   the containers arent being passed by ref here so my output is messed up (or so i think)
*/

template <typename... Args>
auto gen_tuple_start(Args&&... args) {
    return std::make_tuple((std::forward<Args>(args).begin())...);
}

template <typename... Args>
auto gen_tuple_end(Args&&... args) {
    return std::make_tuple((std::forward<Args>(args).end())...);
}

template <typename... Args>
auto gen_tuple_start_wrapper(Args&&... args)
{
    return gen_tuple_start(forward<Args>(args)... );
}

template <typename... Args>
auto gen_tuple_end_wrapper(Args&&... args)
{
    return gen_tuple_end(forward<Args>(args)... );
}


int main()
{
    vector<int> vec{1,2,33};
    deque<int> vec1{4,5,6};
    auto s = gen_tuple_start_wrapper(vec,vec1);
    auto e = gen_tuple_end_wrapper(vec,vec1);
    
    // now iterating over
    
    auto f = get<0>(s);
    
    auto g = get<0>(e);
        
   while(f!=g)
   {
       cout << *f << " ";
       ++f;
   }
    
    cout << endl;
    
    auto h = get<1>(s);
    auto i = get<1>(e);
    
    while(h!=i)
   {
       cout << *h << " ";
       ++h;
   }
    

}
