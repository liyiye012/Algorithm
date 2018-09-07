#include<vector>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<cstdio>
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
    void Replace(std::string &str, const std::string &srcSubStr, const std::string &dstSubStr) {
        
        std::string::size_type pos = 0;
        std::string::size_type srclen = srcSubStr.size();
        std::string::size_type dstlen = dstSubStr.size();

        while ((pos = str.find(srcSubStr, pos)) != std::string::npos)
        {
            str.replace(pos, srclen, dstSubStr);
            pos += dstlen;
        }
        cout << str;
    }

    //参考答案
    char* ReplaceSubStr(const char*str, const char* srcSubStr, const char* dstSubStr, char *out) {
        int i;
        const char * ptr_str;
        char * ptr_out = out;
        for (i = 0; i<strlen(str);) {
            if ((ptr_str = strstr(str + i, srcSubStr)) == NULL) {
                memcpy(ptr_out, str + i, strlen(str + i) + 1);
                break;
            }
            else {
                memcpy(ptr_out, str + i, ptr_str - (str + i));
                ptr_out += ptr_str - (str + i);
                memcpy(ptr_out, dstSubStr, strlen(dstSubStr));
                ptr_out += strlen(dstSubStr);
                i = ptr_str - str + strlen(srcSubStr);
            }
        }
        return out;
    }
};
/*
使用C语言，实现字符串子串替换接口，可以假设替换前和替换后的字符串都有最大长度限制
输入描述：
字符串远传，被替换的子串，目标子串
输出描述：
替换后的新字符串

备注：
考察C语言基本功底
*/
int main() {
    string str, srcSubStr, dstSubStr;
    getline(cin,str);
    getline(cin,srcSubStr);
    getline(cin, dstSubStr);
    Solution sol;
    //sol.Replace(str, srcSubStr, dstSubStr);

    return 0;
}