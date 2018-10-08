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

*/
//inline bool checkis(int a, int b, int nn) {
// 
void output(vector<long long> res) {
    for (auto a : res) {
        cout << a << " ";
    }
    cout << endl;
}
void solve() {
    long long m;
    long long a, b, n;
    cin >> m >> a >> b >> n;
    int index;
    vector<bool> bad(m+1,true);
    while (cin >> index) {
        bad[index] = false;
    }
    vector<long long> res(m + 1, 0);
    res[0] = 1;
    for (long long i = 1; i <= m; i++) {
        for (long long j = min(i + a, m); j <= min(m, i + b); j++) {
            if (bad[j]) {
                res[j] = res[i] + 1;
                res[j] %= 1000000007;
            }
        }
    }
    output(res);
    cout << res[m];
}
int main() {
    //freopen("in.txt", "r", stdin);
    solve();
    return 0;
}