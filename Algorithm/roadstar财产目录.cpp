#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <map>
#include <set>

using namespace std;
/*
    公司中有些设备共享同一编号，有些设备编号超出所在编号区间，从1-n中选择数字按照升序
    进行编号，以满足要求的编号无需更改（重复的编号保留第一次出现的设备编号，更改的编号保持升序）
    现给定n台设备的编号，对n台设备按照如上要求重新编号

    第一行输入包含设备数n
    第二行含有n个正整数a1,a2,...,an表示当前设备编号
*/
int main() {
    freopen("in.txt", "r", stdin);
    int n, x;
    vector<int> data, vis;
    set<int> s;//set 是从小到大自动排好序的有序集合
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        data.push_back(x);
        s.insert(i + 1);
        vis.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        if (s.find(data[i]) != s.end()) {//去重复的数字
            vis[i] = 1;
            s.erase(data[i]);
        }
        else { vis[i] = 0; }
    }
    //for (auto a : s) cout << a << " "; cout << endl;
    for (int i = 0; i < n; i++) { //按照升序将1-n中没出现过的编号分配给设备
        if (vis[i] == 0) {
            // cout << i << " ";             
            data[i] = *s.begin();
            s.erase(*s.begin());
        }
    }     // cout << endl;     
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;

}