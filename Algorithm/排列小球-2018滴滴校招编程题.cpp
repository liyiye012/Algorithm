#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#define ll long long
#define maxn 2005
#define mod 1000000007
using namespace std;
/*
排列小球
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
给定三种类型的小球P、Q、R，每种小球的数量分别为np、nq、nr个。现在想将这些小球排成一条直线，但是不允许相同类型的小球相邻，问有多少种排列方法。如若np=2，nq=1，nr=1则共有6种排列方式：PQRP，QPRP，PRQP，RPQP，PRPQ以及PQPR。 如果无法组合出合适的结果，则输出0。

输入
一行以空格相隔的三个数，分别表示为np，nq，nr。

输出
排列方法的数量。


样例输入
2 1 1
样例输出
6

*/

ll n, q, x, sum, cur;
ll a[maxn], fac[maxn], c[maxn][maxn], f[3][maxn];

void Pre() {
    fac[0] = 1;
    for (int i = 1; i <= n; i++)fac[i] = 1ll * i*fac[i - 1] % mod;
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        c[i][0] = c[i][i] = 1;
    }
    return;
}

void solve() {
    int np, nq, nr;
    cin >> np >> nq >> nr;
    cout << np + nq + nr;
}
int main() {
    //freopen("in.txt", "r", stdin);
    /*solve();*/
    cin >> n >> q;
    n = 3;
    for (int i = 1; i <= n; i++) a[i] = gi();
    Pre();
    sum = 0; cur = 0;
    f[cur][0] = 1;
    for (int i = 1; i <= n; i++) {
        cur ^= 1;
        for (int t = 0; t <= a[i] + sum + 1; t++)
            f[cur][t] = 0;
        for (int k = 1; k <= a[i] && k <= sum + 1; k++)
            for (int j = 0; j <= sum; j++)
                for (int l = 0; l <= k && l <= j; l++) {
                    f[cur][j - l + a[i] - k] +=
                        1ll * f[cur ^ 1][j] * c[a[i] - 1][k - 1] % mod*(1ll * c[j][l] * c[sum + 1 - j][k - l] % mod) % mod;
                    f[cur][j - l + a[i] - l] %= mod;
                }
        sum += a[i];
    }
    cout << f[cur][0];

    return 0;
}