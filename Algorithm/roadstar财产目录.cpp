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

void solve(int n,vector<int> num) {
    unordered_map<int, int> freq;
    for (int i = 0; i < num.size(); i++) {
        if (freq.find(i) == freq.end()) freq[i] = 1;
        else freq[i]++;
    }
    
}
int main() {
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> num;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        num.push_back(tmp);
    }
    solve(n, num);
    return 0;
}