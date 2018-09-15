#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
/*
链接：https://www.nowcoder.com/questionTerminal/7442938f5012486499ddd61ce16f9086
来源：牛客网

如果一个数字满足以下条件,我们就称它为奇异数:
1、这个数字至少有两位
2、这个数的最低两位是相同的
比如: 1488是一个奇异数,而3、112不是。
牛牛现在给出一个一个区间[L,R],让你计算出在区间内有多少个奇异数
输入描述:
输入包括两个正整数L和R(1 ≤ L ≤ R ≤ 10^12),以空格分割。


输出描述:
输出一个正整数,即区间内的奇异数的个数。
示例1
输入
10 20
输出
1
*/

int main() {
    string s;
    int r[55], g[55];
    while (cin >> s) {
        r[0] = g[0] = 0;
        for (int i = 0; i<s.size(); i++) {
            if (s[i] == 'R') {
                r[i + 1] = r[i] + 1;
                g[i + 1] = g[i];
            }
            else {
                r[i + 1] = r[i];
                g[i + 1] = g[i] + 1;
            }
        }
        ///统计R和G的数量
        int sumR = r[s.size()];
        int sumG = g[s.size()];
        ///最坏情况，就是把R全变为G或者把G全部变为R
        int res = min(sumR, sumG);
        for (int i = 1; i <= s.size(); i++) {
            ///遍历每个点需要修改的数量，记录最小值即可
            res = min(res, g[i] + sumR - r[i]);
        }
        cout << res << endl;
    }
    return 0;
}
