#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std; 
/*
质数平方和
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
输入正整数N (N <= 1000)，输出所有小于等于N的质数的平方和。

输入
一行一个正整数N

输出
一行一个正整数，表示所有小于等于N的质数的平方和


样例输入
5
样例输出
38

Hint
2^2+3^2+5^2=38
温馨提示
请尽量在全场考试结束10分钟前调试程序，否则由于密集排队提交，可能查询不到编译结果
点击“调试”亦可保存代码
编程题可以使用本地编译器，此页面不记录跳出次数
*/
bool prime(int num) {
    bool flag = true;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num%i == 0) {
            flag = false;
        }
    }
    return flag;
}
void solve() {
    int N;
    cin >> N;
    int sum = 0;
    for (int i = 2; i <= N; i++) {
        if (prime(i)) sum = sum + (i*i);
    }
    cout << sum;
}
int main() {
    //freopen("in.txt", "r", stdin);
    solve();




    return 0;
}