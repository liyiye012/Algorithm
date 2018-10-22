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
#include <assert.h>
using namespace std;
void output(vector<int> arr) {
    for (auto a : arr) {
        cout << a << " ";
    }cout << endl;
}
void solve() {
    int n;
    cin >> n;
    int li, ri;
    vector<pair<int, int>> num;
    for (int i = 0; i < n; i++) {
        cin >> li >> ri;
        num.push_back(make_pair(li, ri));
    }
    int remove = 0;
    for (int i = 0; i < num.size(); i++) {
        for (int j = i + 1; j < num.size(); j++) {
            if (num[i].first >= num[j].first && num[i].second <= num[j].second) { 
                
                remove++; 
                break;
            }
        }
    }
    cout << remove;
}
int main() {
    freopen("in.txt", "r", stdin);
    solve();
    return 0;
}