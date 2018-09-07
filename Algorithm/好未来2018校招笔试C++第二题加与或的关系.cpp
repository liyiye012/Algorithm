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
        long long x, k, ans, i, j, a, lenX, lenK, lenA;
        int posX[160], posK[160], posA[160];
        
            memset(posX, 0, sizeof(posX));
            cin >> x >> k;
            i = 0, ans = 0;
            while (x > 0) {
                posX[i++] = x & 1;
                x = x >> 1;
            }
            lenX = i;
            i = 0;
            while (k>0)
            {
                posK[i++] = k & 1;
                k = k >> 1;
            }
            lenK = i;

            for (i = 0, j = 0, a = 0; j < lenK; i++) {
                if (posX[i] == 0) posA[a++] = posK[j++];
                else posA[a++] = 0;
            }
            lenA = a;
            for (i = lenA - 1; i >= 0; i--) {
                ans = ans << 1;
                ans = ans | posA[i];
            }
            cout << ans << endl;
    }
};
/*
��Ŀ������
һ����ʽx + y = x|y ����һ��������x, �����ʽ��������y�кܶ�裬�ӵ�һ����ʼ��С������y��
����һ��������k��������Ҫ��ĵ� k �� y

����������
����t��ʾ��t�����ݣ�t<100)
ÿ����������x��k

���������
���y

˼·: λ���㡣�� k ������λ�ӵ͵�����䵽 x ��ӦΪ0��λ�ϡ�

���� x = 2 =0b10

k = 1 = 0b1 , y = 0b01

k = 2 = 0b10 , y = 0b100(�Ӵֵ�1����ΪҪ����x��Ӧ��1)
*/
int main() {
    Solution solution;
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solution.solve();
    }
    return 0;
}