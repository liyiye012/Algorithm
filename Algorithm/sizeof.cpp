#include<iostream>
using namespace std;
//class A {
//
//};
//class B {
//public:
//    B() { };
//    ~B() {};
//};
//class C {
//public:
//    C() {};
//    ~C() {};
//    static void f() {};
//private:
//    int a;
//    char c;
//    char * p;
//    static int sa;
//};
//class D :public C{
//public:
//    D() {};
//    ~D() {};
//private:
//    char e;
//    int d;
//};

//class A
//{
//public:
//    int a;
//};
//class B : public A
//{
//public:
//    int b;
//};
//class C : public A
//{
//public:
//    int c;
//};
//class D : public B, public C
//{
//public:
//    int d;
//};
class A {
public:
    virtual void f()=0;
};
int main() {
    cout << "sizeof A=" << sizeof(A) << endl;
    //cout << "sizeof B=" << sizeof(B) << endl;
    //cout << "sizeof C=" << sizeof(C) << endl;
    //cout << "sizeof D=" << sizeof(D) << endl;
}