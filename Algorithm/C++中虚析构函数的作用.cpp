#include<iostream>
using namespace std;
//C++中虚析构函数的作用
class ClxBase
{
public:
    ClxBase() {};
    virtual ~ClxBase() {};//尝试去掉virtual则子类的析构函数不会被调用

    virtual void DoSomething() { cout << "Do something in class ClxBase!" << endl; };
};

class ClxDerived : public ClxBase
{
public:
    ClxDerived() {};
    ~ClxDerived() { cout << "Output from the destructor of class ClxDerived!" << endl; };

    void DoSomething() { cout << "Do something in class ClxDerived!" << endl; };
};
int main() {
    
    ClxBase *pTest = new ClxDerived;
    pTest->DoSomething();
    delete pTest;
}



