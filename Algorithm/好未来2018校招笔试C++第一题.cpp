#include<vector>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;
/*
һ�����ִ����Ա��𿪳ɶ�����ִ�������12345���12 3 45 ����123 45����һ�����������͵����ִ�n����n�𿪺�����ܱ�3�������������m�Ƕ��٣�0Ҳ��3�ı�����
������n=12345����ɣ�
��1����12�� 3��45��m=3
(2):123,45,m=2
����������
����һ�����������͵����ִ�n������С��100
���������
���һ�����ֱ�ʾn�𿪺��ܱ�3������������
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
    //�ҵĽⷨ ֻ��ͨ��83%
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
    ˼·�� ��ǰ���ɨ�裬̰�ģ� ��������Ҫ��ļ�����ȥ��

    m ��¼ǰ�󼸸������֮�ͣ���󲻳���3 ��111 222��, c1 c2 ��¼��λ�� 3 ����1 ��2 ������� m>0 && m%3==0 || c1 >1 && c2 >2 ��λ
    ĳ�������Ա� 3 ���� continue
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
            //�ж��ܲ�����һ�����
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