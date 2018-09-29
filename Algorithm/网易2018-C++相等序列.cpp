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
void solve() {
    int n;
    cin >> n;
    vector<int> num;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        num.push_back(temp);
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.find(num[i]) != mp.end()) mp[num[i]]++;
        else mp[num[i]] = 1;
    }
    if (mp.size() > 3) cout << "NO" << endl;
    else if (mp.size() == 1 || mp.size() == 2) cout << "YES" << endl;
    else {
        vector<int> res;
        for (auto m : mp) {
            res.push_back(m.first);
        }
        if (res[0] - res[1] == res[1] - res[2]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
int main() {
    freopen("in.txt", "r", stdin);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {

        solve();
    }
    return 0;
}