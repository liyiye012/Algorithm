#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>


#include<functional>
using namespace std;

void output(vector<int> arr) {
    for (auto a : arr) {
        cout << a << " ";
    }cout << endl;
}
/*
幸运ID
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 131072KB；其他语言 655360KB
题目描述：
小C有一张票，这张票的ID是长度为6的字符串，每个字符都是数字，他想让这个ID变成他的辛运ID，所以他就开始更改ID，每一次操作，他可以选择任意一个数字并且替换它。

如果这个ID的前三位数字之和等于后三位数字之和，那么这个ID就是辛运的。你帮小C求一下，最少需要操作几次，能使ID变成辛运ID

输入
输入只有一行，是一个长度为6的字符串。

输出
输出这个最小操作次数


样例输入
000000
样例输出
0

Hint
输入样例2
000018

输出样例2
1

样例解释：将前三位任意一个改为9即可满足条件，操作数为1
温馨提示*/

//贪心算法+双指针
/*作者：ccccccccccccccc
链接：https://www.nowcoder.com/discuss/109903
来源：牛客网

思路 : 前三个数是一个数组，后三个数是一个数组。如果两个数组和不相等，那么调整的基本思路如下，要么将小数组中的最小值调大，要么将大数组中的最大值调小，具体是调大数组，还是调小数组，取决于 最大值和最小值能调整的幅度。
*/
int dif(vector<int> arr1, vector<int> arr2, int num) {
    sort(arr1.begin(), arr1.end());
    arr1.push_back(INT_MIN);
    sort(arr2.begin(), arr2.end(),std::greater<int>()); //从大到小排序，需要 #include<functional>
    arr2.push_back(INT_MAX);

    int i = 0;
    int j = 0;
    int c = 0;

    while (num > 0) {
        int cur1 = arr1[i];
        int cur2 = arr2[j];
        int val = 0;
        if (9 - cur1 > cur2 - 0) {
            val = 9 - cur1;
            j++;
        }else{
            val = cur2 - 0;
            i++;
        }
        if (val > num) num = 0;
        else num -= val;
        c++;
    }
    return c;
}
int solve(vector<int> n) {
    int sum1 = 0, sum2 = 0;
    vector<int> num1, num2;
    for (int i = 0; i < 3; i++) { 
        num1.push_back(n[i]);
        sum1 += n[i]; 
    }
    for (int j = 3; j < 6; j++) { 
        num2.push_back(n[j]);
        sum2 += n[j]; 
    }
 
    // To Do
    int res = 0;
    if (sum1 < sum2) res = dif(num1, num2, sum2 - sum1);
    else res = dif(num2, num1, sum1 - sum2);
    

    return res;
}
int main() {
    string s;
    cin >> s;
    vector<int> n;
    for (int i = 0; i < 6; i++) {
        n.push_back(s[i] - '0');
    }
    // output(n);
    cout << solve(n);
    return 0;
}