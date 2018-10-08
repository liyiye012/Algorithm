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
//} 
void solve() {
    string str;
    cin >> str;
    unordered_map<int, int> mp;
    for (int i = 0; i<str.size(); i++) {
        if (mp.find(str[i] - '0') == mp.end()) mp[str[i] - '0'] = 1;
        else  mp[str[i] - '0']++;
    }
    int sum = 0;
    for (int i = 0; i<mp.size(); i++) {
        sum += mp[i]*(mp[i] - 1) / 2;
    }
    
    cout << sum << endl;
}
int main() {
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}