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

};
int main() {
    Solution solution;
    int n[] = { 6, 7, 5, 9, 8 };
    vector<int> nums(n, n + 5); //将数组n的前5个元素作为向量a的初值
                                //solution.output(nums);
                                //vector<int> nums(&n[1], &n[4]);//将n[1] - n[4]范围内的元素作为向量a的初值 ????
                                //solution.output(nums);
                                /*  p1 = { 0,3 };
                                p2 = { 1,1 };
                                p3 = { 3,4 };
                                p4 = { 5,6 };
                                vector<Point> p;
                                p.push_back(p1);
                                p.push_back(p2);
                                p.push_back(p3);
                                p.push_back(p4);*/
                                //string A = "this apple is sweet";
                                //string B = "this apple is sour";
                                //vector<string> res=solution.uncommonFromSentences(A, B);
                                //for (auto a : res) {
                                //    cout << a << "  ";
                                //}
    return 0;
}