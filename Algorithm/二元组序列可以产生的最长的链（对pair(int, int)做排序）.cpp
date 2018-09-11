#include<iostream>
#include<vector>
#include <string>
#include <stdio.h>
#include <string.h> 
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <assert.h>
using namespace std;
void output(vector<pair<int, int>> p) {
    cout <<endl<< "---------output---------" << endl;
    for (int i = 0; i<p.size(); i++) {
        cout << "(" << p[i].first << "," << p[i].second << ")";
    }
}
void output(vector< int> p) {
    cout << endl << "---------output---------" << endl;
    for (int i = 0; i<p.size(); i++) {
        cout << p[i]<<" ";
    }
    cout << endl;
}
bool judge(const pair<int, int> a, const pair<int, int> b) {
    if (a.first == b.first) return a.second<b.second;
    else
        return a.first < b.first;// a.first < b.first就是从小到大排序
}
/*
宜信2018笔试
输入一个包含n对的二元组序列，其中每一个二元组都有正整数组成，并且第一个数字比第二个小。对于两个二元组（a,b)和(c,d),如果b<c,那么二元组(c,d)可以连接在另外一个二元组（a,b)之后。依次规则，我们可以将二元组连成一个链。请输出这个二元组序列可以产生的最长的链

输入5 24 39 60 15 28 27 40 50 90
输出(5,24)(27,40)(50,90)

另外我觉得这题可能是从leetcode 435. Non-overlapping Intervals这题改的，只是求的结果是它的补集
*/
void main() {
    int val=0;
    freopen("in.txt", "r", stdin);
    vector<int> nums;
    //while (cin >> val) {
    //    nums.push_back(val);
    //}
    string in;
    getline(cin,in);
    int i = 0;
    while (i < in.size()) {
        //cout << "i=" << i << "   val=" << val << endl;
        if (in[i] == ' ') {
            val = 0;
            i++;
        }
        while (in[i] != ' ' && i < in.size()) {
                val = val * 10 + (in[i] - '0');
                i++;
            }
            nums.push_back(val);
        //cout << "i=" << i << "   val=" << val << endl;
    }
    //output(nums);
    vector<pair<int, int>> p;
    for (int i = 0; i < nums.size(); ) {
        //cout << "i=" << i << endl;
        p.push_back(make_pair(nums[i], nums[i + 1]));
        i += 2;
    }
    //output(p);
    sort(p.begin(), p.end(), judge);
    //output(p);
    cout << "(" << p[0].first << "," << p[0].second << ")";
    int slow = 0, fast = 0;
    for (int i = 1;i<p.size();i++) {
        if (p[i].first > p[slow].second) { 
            cout << "(" << p[i].first << "," << p[i].second << ")"; 
            slow = i;
        }
    }
}