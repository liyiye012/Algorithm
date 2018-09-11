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
�������������飬�����Ԫ�غͣ�Ҫ��Ԫ�ش�С�����������
int[] data={5,1,3,4,9,7,6,8}
������������ǣ�1��3��4��7��8

����������
���������飬�ٶ����鳤��<100��Ԫ�����ֵ<10000

���������
����������

˼·leetcode 300. Longest Increasing Subsequence
����ά��һ��һάdp���飬����dp[i]��ʾ��nums[i]Ϊ��β��������Ӵ�������ͣ�
����ÿһ��nums[i]�����Ǵӵ�һ������������i��
�������ĳ����С��nums[i]�����Ǹ���dp[i]��
���·���Ϊdp[i] = max(dp[i], dp[j] + nums[i])��
���Ƚϵ�ǰdp[i]��ֵ���Ǹ�С��num[i]������dpֵ��1�Ĵ�С��
���Ǿ��������ϵĸ���dp���飬�����dp����������ֵ��������Ҫ���ص�LIS�ĳ���

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