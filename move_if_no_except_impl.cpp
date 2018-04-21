#include <iostream>
#include <memory>
#include <utility>
#include <type_traits>

using namespace std;

class A
{
    public:
    A()
    {
        //cout << "A ctor\n";
    }
    A(const A&) = default;
    virtual ~A()
    {
       // cout  << "A dtor\n";
    }
    A(A&& other)
    {
       static_cast<void>(other);
    }
};

class B
{
    public:
    B()
    {
        //cout << "B ctor\n";
    }
    ~B()
    {
        //cout << "B dtor\n";
    }
    B(B&& other) noexcept
    {
        static_cast<void>(other);
        return;
    }
};

template <typename T>
auto move_if_no_except(T&& obj,  typename enable_if<!noexcept(decay_t<T>(declval<decay_t<T>>()))>::type* = nullptr)
{
    cout << "non-move\n";
    return obj;
}

template <typename T>
auto move_if_no_except(T&& obj,  typename enable_if<noexcept(decay_t<T>(declval<decay_t<T>>()))>::type* = nullptr)
{
    cout << "move\n";
    return std::move(obj);
}


int main(void)
{
   A a;
   B b;
   
    move_if_no_except(a);
    move_if_no_except(b);
}


