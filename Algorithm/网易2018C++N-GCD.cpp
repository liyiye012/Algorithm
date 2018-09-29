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

int gcd(int x, int y)
{
    int z = y;
    while (x%y != 0)
    {
        z = x%y;
        x = y;
        y = z;
    }
    return z;
}
int ngcd(int n, vector<int> num) {
    int number = num[0];
    for (int i = 1; i < n; i++) {
        number = gcd(number, num[i]);
    }
    return number;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        res.push_back(temp);
    }
    int nGCD = -1;
    int mnum = max(res[0][0], res[0][1]);
    for (int i = 1; i < n; i++) {
        mnum = gcd(mnum, max(res[i][0], res[i][1]));
    }
    if(mnum==1)    cout << nGCD;
    else cout << mnum;

}
int main() {
    freopen("in.txt", "r", stdin);
    solve();
    return 0;
}