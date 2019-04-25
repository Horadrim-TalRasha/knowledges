#include <stdio.h>

class foo
{
public:
    foo()
    { member_ = 10; }

    ~foo()
    {}

    int func0()
    {
        printf("func0 was called\n");
        return 0;
    }

    int func1(int arg)
    {
        return arg;
    }

public:
    int member_;
};

template<typename _T, typename _R>
class temp_wrapper;

template<typename _T, typename _R>
class temp_wrapper<_T, _R (_T::*)()>
{
public:
    typedef _R (_T::*MethodType)();
    void bar(_T & t, MethodType method)
    {
        _T * p = &t;
        (p->*method)();
    }
};
/**  To access the member of template parameter class but failed.
 *   usage of template class will like following
 *   temp_wrapper<foo, int (foo::*)> t2;
 *   t2.bar(a, &foo::member_);
template<typename _T, typename _R>
class temp_wrapper<_T, _T::value_type>
{
public:
    typedef _T::value_type MemberType;
    void bar(_T & t, MemberType m)
    {
        _T * p = &t;
        printf("Member m: %d\n", p->m);
    }
};
**/

int main(int argc, char ** argv)
{
    typedef int (foo::*MethodType)();
    MethodType method = &foo::func0;
    foo a;
    foo * p = &a;
    (p->*method)();

    temp_wrapper<foo, int (foo::*)()> t;
    t.bar(a, &foo::func0);

    return 0;
}
