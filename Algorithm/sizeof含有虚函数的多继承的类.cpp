#include <iostream>
using namespace std;

class Base1 {
    virtual void fun1() {}
    virtual void fun11() {}
public:
    virtual ~Base1();
};

class Base2 {
    virtual void fun2() {}
};

class DerivedFromOne : public Base2
{
    virtual void fun2() {}
    virtual void fun22() {}
};

class DerivedFromTwo : public Base1, public Base2
{
    virtual void fun3() {}
};

void main()
{
    cout << "sizeof Base1 " << sizeof(Base1) << endl;
    cout << "sizeof Base1 " << sizeof(Base2) << endl;
    cout << "sizeof FromOne " << sizeof(DerivedFromOne) << endl;
    cout << "sizeof FromTwo " << sizeof(DerivedFromTwo) << endl;
    getchar();
}