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
 大小写转换
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
输入一个由字母和数字组成的字符串，请将其中的大写字母转换成小写输出，小写字母转换成大写输出，其他字符不变

输入
一行一个由字母和数字组成的字符串，长度不超过100

输出
一行一个由字母和数字组成的字符串


样例输入
IlovePonyAI666
样例输出
iLOVEpONYai666
*/
bool ischaracter(string str,int i) {
    bool is = false;
    char c = str[i];
    if (((c - 'a' >= 0) && (c - 'z' <= 0)) || ((c - 'A' >= 0) && (c - 'Z' <= 0))) is = true;
     return is;
}
void solve() {
    string str;
    cin >> str;
    string res = "";
    for (int i = 0; i < str.size(); i++) {
        if (ischaracter(str,i)) {
            //cout << "ischar" << endl;
            if ((str[i] - 'a' >= 0) && (str[i] - 'z' <= 0)) {
                res += 'A' + (str[i] - 'a');
            }
            else if ((str[i] - 'A' >= 0) && (str[i] - 'Z' <= 0)) {
                res += 'a' + (str[i] - 'A');
            }
        }

        else { 
            //cout << "isnumber" << endl;
            res += str[i]; 
        }

        //cout << "i="<<i<<"    "<<res << endl;
    }
    cout << res;
}
int main() {
    //freopen("in.txt", "r", stdin);
    solve();




    return 0;
}