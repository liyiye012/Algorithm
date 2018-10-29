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
bool check(vector<int> num) {
    bool flag = true;
    if ((num[0] + num[num.size() - 1] != 1) && (num[0]!=-1) &&(num[num.size()-1]!=-1)) flag = false;
    for (int i = 1; i < num.size()-1; i++) {
        if (num[i] == -1 ||(num[i-1] == -1) || (num[i +1] == -1) || ((num[i] + num[i - 1] == 1) && (num[i] + num[i + 1] == 1))) {
            continue;
        }
        else flag = false;
        break;
    }
    return flag;
}
void solve() {
    vector<int> num;
    char c;
    while (cin >> c) {
        if (c == 'L') num.push_back(0);
        else num.push_back(1);
    }
    int remove = 0;
    if ((num[0] + num[num.size() - 1] != 1) ) {
        num[0] = -1;
        remove++;
        
    }
    for (int i = 1; i < num.size()-1; i++) {
        //cout << "i=" << i << endl;
        if(! (num[i] == -1 || (num[i - 1] == -1) || (num[i + 1] == -1) || ((num[i] + num[i - 1] == 1) && (num[i] + num[i + 1] == 1)))) {
            num[i] = -1;
            remove++;
            if (check(num)) break;
        }
        
    }
    if ((num[0] + num[num.size() - 1] != 1) &&(num[0]!=-1)) {
        num[num.size() - 1] = -1;
        remove++;

    }
    cout << remove;
}
int main() {
    //  freopen("in.txt", "r", stdin);
    solve();
    return 0;
}