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
unordered_map<string, int> name;
vector<vector<string>> namevec;
void solve() {
    string s;
    cin >> s;
    if (name.find(s) == name.end()) {
        cout << "OK" << endl;
        name[s] = 1;
    }
    else {
        string news = "";
        news += s;
        news+=('0' + name[s]);
        
        name[s]++;
        name[news]=1;
        cout << news << endl;
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}