#include<iostream>
using namespace std;
//�����С�����й��캯�������������Ĵ�С���麯��ָ���С
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