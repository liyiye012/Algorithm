#include<vector>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;
struct Point {
    int x;
    int y;
}p1, p2, p3, p4;
class Solution {
public:
    void output(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    void output(vector<vector<int>> dislikes) {
        for (int i = 0; i<dislikes.size(); i++) {
            cout << dislikes[i][0] << "," << dislikes[i][1] << endl;
        }
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if (N == 0 && dislikes.size() == 0) return true;
        dislikes.erase(dislikes.begin());
        output(dislikes);
        return false;
    }

    void pushstr(string str, unordered_map<string, int> &mp) {
        string s = "";
        for (int i = 0; i<str.size(); i++) {
            if (str[i] != ' ') s += str[i];
            else if (str[i] == ' ') {
                if (mp.find(s) != mp.end()) mp[s]++;
                else if (mp.find(s) == mp.end()) mp[s] = 1;
                s = "";
            }
        }
        if (s.size() > 0) {
            if (mp.find(s) != mp.end()) mp[s]++;
            else if (mp.find(s) == mp.end()) mp[s] = 1;
        }
    }
    void output(unordered_map<string, int> mpa) {
        cout << "output:" << endl;
        for (unordered_map<string, int>::iterator it = mpa.begin(); it != mpa.end(); it++) {
            cout << (*it).first << "  " << (*it).second << endl;
        }
    }
    void solve() {
        int n, m;
        cin >> n >> m;
        vector<int> score(n, 0);
        double sum = 0;
        for (int i = 0; i < n; i++) {
            int sco;
            cin >> sco;
            score[i] = sco;
            sum += sco;
        }
        double e = (sum) / (n - m);
        printf("%.2lf", e);
    }
};
/*
有一个n面的骰子，掷每一面都是等概率的，其中有m个将里面，如果掷到奖励面则可以再掷一次骰子。玩家每掷一次
都能获得掷到那一面的分数。求玩家可获得分数的期望
输入描述：
第一行输入两个数n,m分别表示骰子有n面，有m个面有奖励
第二行输入n个数字用空格隔开，表示n个面的分数

输出描述：
输出期望，保留小数点后两位

思路：
n 面筛子，m面有奖，有奖继续掷筛子，没奖结束。

输入给定 score 数组 s_array, len(s_array) == n， 求期望。

数学题, e =

ave_score = sum(s_array)/n
(n-m)/n * avg_score (第一次就没奖)+
m/n * (score + e) (第一次有奖，相当于从头开始)
化简得到 e = sum(s_array)/n-m
*/
int main() {
    Solution solution;
    solution.solve();
    return 0;
}