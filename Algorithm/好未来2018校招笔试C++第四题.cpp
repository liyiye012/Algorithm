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
int main() {
    Solution solution;
    solution.solve();
    return 0;
}