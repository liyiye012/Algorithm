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

void solve(int n,int m,vector<int> prices, vector<pair<int, int>> youhui) {
    int money = 0;
    for (int i = 0; i < n; i++) {
        bool hui = false;
        for (auto y : youhui) {
            if (prices[i] >= y.first && y.second != 0) {
                cout << "hui: prices[i]=" << prices[i] << "  hui.second=" << y.second << endl;
                money += prices[i] - y.second;
                y.second = 0;
                hui = true;
                }
            if (hui) break;
        }
        if (!hui) money += prices[i];
    }
    cout << money;
}
int main() {
    //freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<int> prices;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        prices.push_back(temp);
    }
    vector<pair<int, int>> youhui;
    int xi, yi;
    for (int i = 3; i <= m + 2; i++) {
        cin >> xi >> yi;
        youhui.push_back(make_pair(xi, yi));
    }
    solve(n,m,prices,youhui);
    return 0;
}