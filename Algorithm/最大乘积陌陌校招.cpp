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
#include <cctype>

using namespace std;
/*
最大乘积
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
有长度为n的整数数组，从这 n 个整数中按照顺序选取m个，要求相邻两个整数在原数组中的位置相差不超过i，使得这 m 个整数的乘积最大，请返回最大乘积。

输入
第一行 整数n （1<n<20）

第二行 按顺序的n个整数   整数的范围在-50 到 50之间

第三行 整数i和m  （1<i<20, 1<m<50)

输出
返回乘积


样例输入
3
7 4 7
2 50
样例输出
49

*/
//inline bool checkis(int a, int b, int nn) {
//
//}
const int N = 110;
const long long inf = 1e16;
long long a[N], mx[N][15], mn[N][15];
void solve() { 
    //int n;
    //cin >> n;
    //vector<int> num;
    //int temp;
    //for (int i = 0; i < n; i++) {
    //    cin >> temp;
    //    num.push_back(temp);
    //}
    //int i, m;
    //cin >> i >> m;
    //
    int n;
    while (scanf("%d", &n) > 0) {
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        int d, m;
        scanf("%d%d", &m, &d);
        for (int i = 1; i <= n; i++) {
            mx[i][0] = 1;
            mn[i][0] = 1;
            for (int j = 1; j <= m; j++) {
                mx[i][j] = -inf;
                mn[i][j] = inf;
            }
        }
        long long mmx = -100, mmn = 100;
        long long ans = -inf;
        for (int i = 1; i <= n; i++) {
            mmx = max(mmx, a[i]);
            mx[i][1] = a[i];
            mn[i][1] = a[i];
            if (m == 1)ans = max(ans, mmx);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= m && j <= i; j++) {
                for (int k = i - 1; k >= max(1, i - d) && k >= j - 1; k--) {
                    mx[i][j] = max(mx[i][j], mx[k][j - 1] * a[i]);
                    mx[i][j] = max(mx[i][j], mn[k][j - 1] * a[i]);
                    mn[i][j] = min(mn[i][j], mn[k][j - 1] * a[i]);
                    mn[i][j] = min(mn[i][j], mx[k][j - 1] * a[i]);
                    if (j == m)ans = max(ans, mx[i][j]);
                }
            }
        }
        printf("%lld\n", ans);
    }

}
int main() {
    //freopen("in.txt", "r", stdin);
    solve();
    return 0;
}