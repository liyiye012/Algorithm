#include <iostream> 
using namespace std;
class A
{
public:
    virtual void foo()
    {
        cout << "A's foo()" << endl;
        bar();
    }
    virtual void bar()
    {
        cout << "A's bar()" << endl;
    }
    void f() {
        cout << "A:" << endl;
    }
};
class B : public A
{
public:
    void foo()
    {
        cout << "B's foo()" << endl;
        A::foo();
    }
    void bar()
    {
        cout << "B's bar()" << endl;
    }
    void f() {
        cout << "B:" << endl;
    }
};
int main()
{
    B bobj;
    A *aptr = &bobj;
    aptr->foo();
    A aobj = *aptr; //转化为A类对象
    aobj.foo();

    B b;
    A *ptr=&b;
    cout << endl;
    ptr->f();
   
}