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

    //验证例程 
    enum number {
        one = 1,
        two = 2,
        three = 3,
        four = 4
    };
    enum number num1;
    cout << "sizeof 枚举结构 enum number =" << sizeof(enum number) << endl;
    cout << "sizeof 定义后的枚举变量 variable num1=" << sizeof(num1) << endl;
    num1 = three;
    cout << "size of  赋值后的枚举变量 =" << sizeof(num1) << endl;
    return 0;
}