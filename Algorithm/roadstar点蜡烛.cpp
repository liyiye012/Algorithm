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
#include<stack>
using namespace std;

void solve(int n, vector<int> num,int k) {
    long long dis= 1000000000;
    int index;
    for (int i = 0; i < n; i++) {
        if (dis > abs(num[i] - 0)) {
            dis = abs(num[i] - 0);
            index = i;
        }
    }
    int cnt = 1;
    int mintime = abs(num[index] - 0);
    //while (cnt <= k) {
    //    cnt++;
    //    if (index > 0 && index < n - 1) {
    //        if (abs(num[index + 1] - num[index]) < abs(num[index] - num[index - 1])) {
    //            mintime += num[index + 1] - num[index];
    //            index++;
    //        }
    //        else {
    //            mintime += num[index ] - num[index-1];
    //            index--;
    //        }
    //    }
    //    if (index == 0) {
    //        mintime += num[index + 1] - num[index];
    //        index++;
    //    }
    //    if (index == n - 1) {
    //        mintime += num[index] - num[index - 1];
    //        index--;
    //    }
    //}
    if (abs(num[index + 1] - num[index]) < abs(num[index] - num[index - 1])) {
        while (cnt <= k) {
            mintime += num[index + 1] - num[index];
            index++;
            cnt++;
        }
        
    }
    else {
        while (cnt <= k) {
            mintime += num[index] - num[index - 1];
            index--;
            cnt++;
        }
    }

    cout << mintime;
}
int main() {
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> num;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        num.push_back(tmp);
    }
    solve(n, num,k);
    return 0;
}