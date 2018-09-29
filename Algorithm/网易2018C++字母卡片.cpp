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
    int n,k;
    cin >>n>> k;
    map<char, int> mp;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (mp.find(c) != mp.end()) mp[c]++;
        else mp[c] = 1;
    }
    //cout << "Running1" << endl;
    vector<pair<char, int>> vtMap;
    for (auto it = mp.begin(); it != mp.end(); it++)
        vtMap.push_back(make_pair(it->first, it->second));
    //cout << "Running2" << endl;
    sort(vtMap.begin(), vtMap.end(),
        [](const pair<char, int> &x, const pair<char, int> &y) -> int {
        return x.second > y.second;
    });
    //cout << "Running3" << endl;
    int maxsco=0;
    for (int i = 0; i < vtMap.size()&& k>0; i++) {
        //cout << "i=" << i <<"   vtMap[i].second="<< vtMap[i].second <<"   maxsco="<<maxsco<<endl;
        if (vtMap[i].second > k) {
            maxsco += k*k;
            k = 0;
        }
        else {
            maxsco += vtMap[i].second*vtMap[i].second;
            k -= vtMap[i].second;
        }
    }
    cout << maxsco;

}
int main() {
    freopen("in.txt", "r", stdin);
    solve();
 
    return 0;
}