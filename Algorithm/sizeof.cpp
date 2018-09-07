#include<iostream>
using namespace std;
//class a {
//
//};
//class b {
//public:
//    b() { };
//    ~b() {};
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

class A
{
public:
    int a,b;
    virtual int add(int a,int b) {
        return a + b;
    }
};
class B : public A
{
public:
    int add(int a) {
        return a;
    }
};
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

int main() {
    cout << "sizeof A=" << sizeof(A) << endl;
    cout << "sizeof B=" << sizeof(B) << endl;
    //cout << "sizeof C=" << sizeof(C) << endl;
    //cout << "sizeof D=" << sizeof(D) << endl;
}