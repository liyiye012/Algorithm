#include<vector>
#include<iostream>
using namespace std; class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteRecursive(nums, 0, result);
        return result;
    }
    void output(vector<vector<int>> result) {
        cout << "start to print" << endl;
        for (int i = 0; i<result.size(); i++) {
            for (int j = 0; j<result[i].size(); j++) {
                cout << result[i][j];
            }cout << endl;
        }
        cout << "end to print" << endl;
    }
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int>> &result) {
        cout << "begin=" << begin << endl;
        cout << "   num=";
        for (int i = 0; i<num.size(); i++) cout << num[i] << " ";
        cout << endl;
        output(result);
        if (begin >= num.size()) {
            result.push_back(num);
            return;
        }
        for (int i = begin; i<num.size(); i++) {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            swap(num[begin], num[i]);
        }
    }
};
void main() {
    Solution s;
    int a[] = { 1,2,3 };
    vector<int> num(&a[0], &a[3]);
    s.permute(num);

}