/*
题目描述

给出三个数字ABC，你可以选择若干个数字，但是这些数字必须是A的倍数，并且至少得选择一个数字。

问是否存在一种选择方案使得这些数字的和对B取余的结果为C，存在输出YES否则输出NO

输入描述

输入包括t(1<=t<=20),ABC(1<=ABC<100)

输出描述

输出YES或NO

示例1

sample input

3
91 16 5
58 16 0
96 12 4

sample output

YES
YES
NO
【思路】暴力一发，测测RP，居然过了（后台数据水吧~），目前没有想到更好的方法。
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 233;
int T, n, m, q;
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &q);
        int sum = 0;
        int v = 1;
        int k = 0;
        bool ok = false;
        for (int i = 1; i <= N; ++i)
        {
            if (i*n%m == q)
            {
                ok = true;
                break;
            }
            if (i == N && i*n%m != q)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}