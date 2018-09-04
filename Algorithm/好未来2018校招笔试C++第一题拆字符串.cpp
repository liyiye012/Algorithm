#include<vector>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;
/*
一个数字串可以被拆开成多个数字串，例如12345拆成12 3 45 或者123 45，给一个正整数类型的数字串n，求n拆开后的数能被3整除的最大数量m是多少（0也算3的倍数）
举例：n=12345，拆成：
（1）：12， 3，45，m=3
(2):123,45,m=2
输入描述：
输入一个正整数类型的数字串n，长度小于100
输出描述：
输出一个数字表示n拆开后能被3整除最多的数量
*/ 
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
    //我的解法 只能通过83%
    void solve1() {
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
    /*
    思路： 从前向后扫描，贪心： 遇到符合要求的继续下去。

    m 记录前后几个数相加之和，最大不超过3 （111 222）, c1 c2 记录单位被 3 除余1 余2 的情况， m>0 && m%3==0 || c1 >1 && c2 >2 归位
    某个数可以被 3 整除 continue
    */
    void solve() {
        string str;
        cin >> str;
        int i, len = str.length(), m, number, ans = 0, c1, c2;
        for (i = 0, m = 0, c1 = 0, c2 = 0; i < len; i++) {
            number = str[i] - '0';
            if (number % 3 == 0) {
                ans++;
                m = 0, c1 = 0, c2 = 0;
                continue;
            }
            m += number;
            if (number % 3 == 1) c1++;
            else c2++; 
            //判断能不能有一个组合
            if ((m > 0 && m % 3 == 0) || (c1 > 0 && c2 > 0)) {
                ans++;
                m = 0, c1 = 0, c2 = 0;
            }
        }
        cout << ans << endl;
    }
};
int main() {
    Solution solution; 
    solution.solve();
     
    return 0;
}