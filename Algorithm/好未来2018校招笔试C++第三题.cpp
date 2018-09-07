#include<vector>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<cstdio>
using namespace std;
class Solution {
public:
 
    void solve(vector<int> num,vector<string> & s, int index) { 
    }
};
/*
求给定位置下的数组的排列组合

题目描述：
对于固定数组{0，1，2，3，4，5，6，7，8，9}
输入布尔数组{0，1，1，1，1，1，1，1，1，0}
其中0表示对应下标书组元素可出现也可以不出现，1表示必须出现输出所有可能性组合，转换成字符串，并按照字符串升序排序
012345678
0123456789
12345678
123456789

输入描述：
位置出现的布尔值

输出描述：
打印所有组合

思路：求多个数组的笛卡尔积
*/
int main() {
    vector<string> arr;
    int a[11];
    for (int i = 0; i<10; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i<(1 << 10); i++)
    {
        int f = 0;
        for (int j = 0; j<10; j++)
            if (!((i&(1 << j))) && a[j])
            {
                f = 1;
                break;
            }
        if (f)
            continue;
        string str = "";
        for (int j = 0; j<10; j++)
            if (i&(1 << j))
                str.push_back('0' + j);
        arr.push_back(str);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i<arr.size(); i++)
        cout << arr[i] << endl;
    return 0;
    return 0;
}