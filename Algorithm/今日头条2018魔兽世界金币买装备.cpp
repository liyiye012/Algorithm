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
void output(vector<pair<int, int>> equ) {
    for (int i = 0; i < equ.size(); i++) {
        cout << equ[i].first << "  " << equ[i].second << endl;
    }
}
bool sortequ(const pair<int, int> a, const pair<int, int> b) {
    if (a.second / double(a.first) == b.second / double(b.first)) return a.first < b.first;
    return a.second / double(a.first) > b.second /double( b.first);
}
void solve() {
    int n, m, x, y;
    cin >> n >> m;
    vector<pair<int, int>> equ;
    while (cin >> x >> y) {
        equ.push_back(make_pair(x, y));
    } 
    sort(equ.begin(), equ.end(), sortequ);
    //output(equ);
    int maxy = 0;
    while (n > 0 && m > 0) {

            if (m > 0 && n > 0)
            {
                maxy += equ[0].second;
                n -= equ[0].first;
                m--;
                vector<pair<int, int>>::iterator iter = equ.begin();
                equ.erase(iter);
            }

    }
    cout << maxy;
}
int main() {
    freopen("in.txt", "r", stdin);
    solve();
    return 0;
}