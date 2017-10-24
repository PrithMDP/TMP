// Example program
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <deque>

using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::get;
using std::tuple;


// do i need to forward args.begin() to make
template <typename... Args>
auto gen_tuple_start(Args&&... args) {
    return std::make_tuple(std::begin(std::forward<Args>(args))...);
}

template <typename... Args>
auto gen_tuple_end(Args&&... args) {
    return std::make_tuple(std::end(std::forward<Args>(args))...);
}

template <typename... Args>
auto gen_tuple_start_wrapper(Args&&... args)
{
    return gen_tuple_start(std::forward<Args>(args)... );
}

template <typename... Args>
auto gen_tuple_end_wrapper(Args&&... args)
{
    return gen_tuple_end(std::forward<Args>(args)... );
}


int main()
{
    vector<int> vec{1,2,33};
    deque<int> vec1{4,5,6};
    auto s = gen_tuple_start_wrapper(vec,vec1);
    auto e = gen_tuple_end_wrapper(vec,vec1);

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
