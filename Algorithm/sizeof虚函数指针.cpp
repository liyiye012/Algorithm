#include<iostream>
using namespace std;
//空类大小，带有构造函数和析构函数的大小，虚函数指针大小
class A
{
};

class B
{
public:
    B() {}
    ~B() {}
};

class C
{
public:
    C() {}
    virtual ~C() {}
};

int main()
{
    cout << "sizeof(A)=" << sizeof(A) << endl;
    cout << "sizeof(B)=" << sizeof(B) << endl;
    cout << "sizeof(C)=" << sizeof(C) << endl;
    return 0;
}