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
#include <assert.h>
using namespace std;
void output(vector<int> arr) {
    for (auto a : arr) {
        cout << a << " ";
    }cout << endl;
}


class Process
{
    friend Process read(int &a, int &b);
public:
    Process() = default;
    Process(int &a, int &b) : zi(a), mu(b) {}; //构造函数
private:
    int zi = 0, mu = 0; //分子分母
    int result[2];   //结果

public:
    void operator* (const Process &b)  //乘法重载
    {
        //Process c;
        result[0] = this->zi * b.zi;
        result[1] = this->mu * b.mu;
        int j = result[0];
        int k = result[1];
       
        int flag = 1;
        if (j < 0) {
            flag = -1;
            j *= -1;
            result[0] *= -1;
        }
        //cout << result[0] << "/" << result[1] << " ";
        for (auto i = 2; i < ((j < k) ? j : k);)
        {
            if ((result[0] % i == 0 && result[1] % i == 0))
            {
                result[0] = result[0] / i;
                result[1] = result[1] / i;
                continue;
            }
            else
                i++;
        }
        if (result[1] == 1) cout << flag*result[0];
        else if(result[1]>result[0])  
            cout << flag*(result[0] ) << "/" << result[1] << " ";
        else   cout << flag*(result[0]/ result[1] )<<" "<< result[0] % result[1] << "/" << result[1] << " ";
        //return result;
    }

    void operator+ (Process&b)   //加法重载
    {
        int temp[2] = { 0 };
        temp[0] = this->zi*b.mu;
        temp[1] = this->mu*b.zi;
        result[0] = temp[0] + temp[1];
        result[1] = this->mu*b.mu;

        int j = result[0];
        int k = result[1];
        //分子分母 约分
        for (auto i = 2; i < ((j < k) ? j : k);)
        {
            if ((result[0] % i == 0 && result[1] % i == 0))
            {
                result[0] = result[0] / i;
                result[1] = result[1] / i;
                continue;
            }
            else
                i++;
        }
        cout << result[0] << "/" << result[1] << " ";
    }

    void operator/ (const Process &b)  //减法重载
    {
        result[0] = this->zi*b.mu;
        result[1] = this->mu*b.zi;
        int j = result[0];
        int k = result[1];

        int flag = 1;
        if (j < 0) {
            flag = -1;
            j *= -1;
            result[0] *= -1;
        }
        //cout << result[0] << "/" << result[1] << " ";

        for (auto i = 2; i < ((j < k) ? j : k);)
        {
            if ((result[0] % i == 0 && result[1] % i == 0))
            {
                result[0] = result[0] / i;
                result[1] = result[1] / i;
                continue;
            }
            else
                i++;
        }
        if (result[1] == 1) cout << flag*result[0];
        else if (result[1]>result[0])
            cout << flag*(result[0]) << "/" << result[1] << " ";
        else   cout << flag*(result[0] / result[1]) << " " << result[0] % result[1] << "/" << result[1] << " ";
        //return result;

       // cout << flag*result[0] << "/" << result[1] << " ";
    }

    void operator- (const Process &b)  //除法重载
    {
        result[0] = (this->zi * b.mu) - (b.zi * this->mu);
        result[1] = this->mu * b.mu;
        int j = result[0];
        int k = result[1];
        for (auto i = 2; i < ((j < k) ? j : k);)
        {
            if ((result[0] % i == 0 && result[1] % i == 0))
            {
                result[0] = result[0] / i;
                result[1] = result[1] / i;
                continue;
            }
            else
                i++;
        }
        cout << result[0] << "/" << result[1] << " ";
    }
};

Process read(int &a, int &b)  //在类外定义成员函数
{
    Process temp;
    temp.zi = a;
    temp.mu = b;
    return temp;
}


int main() {
    freopen("in.txt", "r", stdin);
    int a = 0, b = 0, c = 0, d = 0;
    int *jie;
    Process first, second;
    string s1;
    cin >> s1;
    if (!s1.find(" ")) {
        int flag = 1;
        int index = 0;
        if (s1[0] == '-') {
            flag = -1;
            index++;
        }
        
        for (int i = index; i < s1.size(); i++) {
            if (s1[i] == '/') {
                index = i; break;
            }
            a = a * 10 + (s1[i] - '0');
        }
        for (int j = index + 1; j < s1.size(); j++) {
            b=b*10+ (s1[j] - '0');
        }
        a = a*flag;
    }
    else  if (s1.find(" ")) {
        int flag = 1;
        int index = 0;
        if (s1[0] == '-') {
            flag = -1;
            index++;
        }
        int aa = 0;
        while (s1[index] != '\0') {
            aa = aa * 10 + (s1[index] - '0');
            index++;
        }
        index++;
        for (int i = index; i < s1.size(); i++) {
            if (s1[i] == '/') {
                index = i; break;
            }
            a = a * 10 + (s1[i] - '0');
        }
        for (int j = index + 1; j < s1.size(); j++) {
            b = b * 10 + (s1[j] - '0');
        }
        a = b*aa + a;
        a = a*flag;
    }
   
    char oper;
    cin >> oper;
   // cin>> c >> d;   //输入分子分母
    string s2;
    cin >> s2;
    if (!s2.find(" ")) {
        int flag = 1;
        int index = 0;
        if (s2[0] == '-') {
            flag = -1;
            index++;
        }

        for (int i = index; i < s2.size(); i++) {
            if (s2[i] == '/') {
                index = i; break;
            }
            c = c * 10 + (s2[i] - '0');
        }
        for (int j = index + 1; j < s2.size(); j++) {
            d = d * 10 + (s2[j] - '0');
        }
        c = c*flag;
    }
    else  if (s2.find(" ")) {
        int flag = 1;
        int index = 0;
        if (s2[0] == '-') {
            flag = -1;
            index++;
        }
        int cc = 0;
        while (s2[index] != ' ') {
            cc = cc * 10 + (s2[index] - '0');
            index++;
        }
        index++;
        for (int i = index; i < s2.size(); i++) {
            if (s2[i] == '/') {
                index = i; break;
            }
            c = c * 10 + (s2[i] - '0');
        }
        for (int j = index + 1; j < s2.size(); j++) {
            d = d * 10 + (s2[j] - '0');
        }
        c = d*cc + c;
        c = c*flag;
    }
   // cout << "c=" << c << "   d=" << d << endl;

    first = read(a, b);    //赋值给第一个分数
    second = read(c, d);   //赋值给第二个分数
    if (oper == '+') {                    // + - * / 运算
        first.operator+(second);
    }
    else if (oper == '-') {
        first.operator-(second);
    }
    else if (oper == '*') {
        first.operator*(second);
    }
    else if (oper == '/') {
        first.operator/(second);
    }
}