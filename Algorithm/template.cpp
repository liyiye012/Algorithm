#include<iostream>
using namespace std;
template<class T>
//类模板定义
class Test {
private:
    T n;
    const T i;
    static T cnt;
public:
    Test():i(0){}
    Test(T k);
    ~Test(){}
    void print();
    T operator+(T x);
};
//B.在类定义体外定义成员函数时，若此成员函数中有模板參数存在，则除了须要和一般类的体外定义成员函数一样的定义外，还需在函数体外进行模板声明**
template<class T>
void Test<T>::print() {
    cout << "n=" << n << endl;
    cout << "i=" << i << endl;
    cout << "cnt=" << cnt << endl;
}
/*
在类定义体外初始化const成员和static成员变量的做法和普通类体外初始化const成员和static成员变量的做法基本上是一样的，
唯一的差别是需再对模板进行声明
*/
template<class T>
int Test<T>::cnt = 0;
template<class T>
Test<T>::Test(T k) :i(k) { n = k; cnt++; }
//函数模板
template<typename T>
T fuc(T x, T y) {
    T z= x + y;
    return z;
}

void main() {
    //模板函数
    double d=1;
    double a=2;
    cout<<fuc(d, a);
}