#include<iostream>
using namespace std;
//C++������������������
class ClxBase
{
public:
    ClxBase() {};
    virtual ~ClxBase() {};//����ȥ��virtual������������������ᱻ����

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



