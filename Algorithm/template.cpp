#include<iostream>
using namespace std;
template<class T>
//��ģ�嶨��
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
//B.���ඨ�����ⶨ���Ա����ʱ�����˳�Ա��������ģ�兢�����ڣ��������Ҫ��һ��������ⶨ���Ա����һ���Ķ����⣬�����ں����������ģ������**
template<class T>
void Test<T>::print() {
    cout << "n=" << n << endl;
    cout << "i=" << i << endl;
    cout << "cnt=" << cnt << endl;
}
/*
���ඨ�������ʼ��const��Ա��static��Ա��������������ͨ�������ʼ��const��Ա��static��Ա������������������һ���ģ�
Ψһ�Ĳ�������ٶ�ģ���������
*/
template<class T>
int Test<T>::cnt = 0;
template<class T>
Test<T>::Test(T k) :i(k) { n = k; cnt++; }
//����ģ��
template<typename T>
T fuc(T x, T y) {
    T z= x + y;
    return z;
}

void main() {
    //ģ�庯��
    double d=1;
    double a=2;
    cout<<fuc(d, a);
}