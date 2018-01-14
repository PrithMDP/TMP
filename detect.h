#include <tuple>
#include <iostream>
#include <array>
#include <utility>
#include <vector>
#include <thread>
#include <memory>
#include <mutex>

using std::cout;
using std::vector;

// Simple utility to find the inner most template type
// std::list<std::vector<int>> -> reutns int

namespace utils{
template <typename T>
struct Detect
{
    using type = T;
};

template <template <typename Type> class Outer, typename Inner>
struct Detect<Outer<Inner>>
{
   using type =  typename Detect<Inner>::type;
};
}//utils

int main()
{
    cout << std::is_same<int, utils::Detect<vector<int>>::type>::value << '\n';
    cout << std::is_same<int, utils::Detect<vector<vector<int>>>::type>::value << '\n';
    
}
