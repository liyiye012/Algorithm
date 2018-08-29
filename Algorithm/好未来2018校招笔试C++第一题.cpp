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
    bool mod3(int n) {
        if (n % 3 == 0) return true;
        else return false;
    }
    void solve() {
        vector<int> num;
        int temp;
        string str;
        getline(cin, str);
        for(int i=0;i<str.size();i++){
            temp = str[i] - '0';
            num.push_back(temp);
        }
        int res = 0;
        bool flag = true;
        int dig = 0;
        for (int i = 0; i < num.size(); i++) {

            if (!flag) {
                dig += num[i];
                if (mod3(dig)) {
                    res++;
                    dig = 0;
                    flag = true;
                    //cout << "i=" << i << "  num[i]=" << num[i] << "   res=" << res << "  dig=" << dig << endl;
                }
                
            }
            else {
                if (flag && mod3(num[i])) { res++; }
                else if (flag && !mod3(num[i])) {
                    flag = false;
                    dig += num[i];
                    //cout << "i=" << i << "  num[i]=" << num[i] << "   res=" << res << "  dig=" << dig << endl;
                }
            }
        }
        cout << res;
    }
  
};
int main() {
    Solution solution; 
    solution.solve();
     
    return 0;
}