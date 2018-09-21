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
void output(vector<int> n) {
    for (auto nn : n) cout << nn << "  ";
}
bool having(int n, vector<int> un) {
    int j = 0;
    while (n) {
        for (auto u : un) if (u == n % 10) return true;
        n = n / 10;
    }

    return false;
}
void solve(int num,vector<int> un) {
    int res = num ;
    while (having(res, un)) {
        res++;
    }
    cout << res;
}
int main() {
    freopen("in.txt", "r", stdin);
    int num;
    cin >> num;
    int unlucky;
    vector<int> un;
    
    un.push_back(0);
    char c;
    cin >> unlucky;
    un.push_back(unlucky);
    while (cin>>c >> unlucky) {
        un.push_back(unlucky);
    }
   // output(un);
    solve(num, un);
    return 0;
}