#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
bool check(int n) {
    if (n<100 || n>999) {
        return false;
    }
    int e, sum = 0;
    for (int i = 0; i<3; i++) {
        e = n % 10;
        sum += (e*e*e);
        n = n / 10;
    }
    return n == sum;
}
int main() {
    int m, n;
    while (cin >> m >> n) {
        vector<int> res;
        for (int i = m; i <= n; i++) {
            if (check(i)) res.push_back(i);
        }
        if (res.empty()) cout << "no" << endl;
        else {
            for (int i = 0; i< res.size(); i++) {
                if (i != res.size() - 1) cout << res[i] << " ";
                else cout << res[i] << endl;
            }
        }
    }
    return 0;
}