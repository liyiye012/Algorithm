#include <iostream>
using namespace std;
typedef enum
{
    Char,
    Short,
    Int,
    Double,
    Float,
}TEST_TYPE;



int main() {
    TEST_TYPE val;
    cout << sizeof(val) << endl;

    //��֤���� 
    enum number {
        one = 1,
        two = 2,
        three = 3,
        four = 4
    };
    enum number num1;
    cout << "sizeof ö�ٽṹ enum number =" << sizeof(enum number) << endl;
    cout << "sizeof ������ö�ٱ��� variable num1=" << sizeof(num1) << endl;
    num1 = three;
    cout << "size of  ��ֵ���ö�ٱ��� =" << sizeof(num1) << endl;
    return 0;
}