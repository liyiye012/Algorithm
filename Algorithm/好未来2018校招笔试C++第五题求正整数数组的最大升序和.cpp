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
 
};
/*
对于正整数数组，求最大元素和，要求元素大小必须是升序的
int[] data={5,1,3,4,9,7,6,8}
最大升序序列是：1，3，4，7，8

输入描述：
正整数数组，假定数组长度<100，元素最大值<10000

输出描述：
对最大升序和

思路leetcode 300. Longest Increasing Subsequence
我们维护一个一维dp数组，其中dp[i]表示以nums[i]为结尾的最长递增子串的数组和，
对于每一个nums[i]，我们从第一个数再搜索到i，
如果发现某个数小于nums[i]，我们更新dp[i]，
更新方法为dp[i] = max(dp[i], dp[j] + nums[i])，
即比较当前dp[i]的值和那个小于num[i]的数的dp值加1的大小，
我们就这样不断的更新dp数组，到最后dp数组中最大的值就是我们要返回的LIS的长度

*/
int arr[100];
void output(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}
int maxSumIS(int arr[], int n)
{
    int i, j, res = 0;
    vector<int> dp(n, 0);
    for (i = 0; i < n; i++)
        dp[i] = arr[i];
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + arr[i]);
    for (i = 0; i < n; i++)
        res = max(res, dp[i]);
        

    return res;
}
int main()
{
    int temp = 0, i = 0;
    while (cin>>temp) {//ctrl+z to exit
        arr[i] = temp;
        i++;
    } 
    printf("%d\n", maxSumIS(arr, 100));
    return 0;
}