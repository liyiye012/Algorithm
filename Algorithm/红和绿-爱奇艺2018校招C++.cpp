#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
链接：https://www.nowcoder.com/questionTerminal/69606208a7734ae0895724cfb951aef8?toCommentId=1862515
来源：牛客网

牛牛有一些排成一行的正方形。每个正方形已经被染成红色或者绿色。牛牛现在可以选择任意一个正方形然后用这两种颜色的任意一种进行染色,这个正方形的颜色将会被覆盖。牛牛的目标是在完成染色之后,每个红色R都比每个绿色G距离最左侧近。牛牛想知道他最少需要涂染几个正方形。
如样例所示: s = RGRGR
我们涂染之后变成RRRGG满足要求了,涂染的个数为2,没有比这个更好的涂染方案。
输入描述:
输入包括一个字符串s,字符串s长度length(1 ≤ length ≤ 50),其中只包括'R'或者'G',分别表示红色和绿色。


输出描述:
输出一个整数,表示牛牛最少需要涂染的正方形数量
示例1
输入
RGRGR
输出
2
*/
int main()
{
    string str = "";
    getline(cin, str);
    int size = str.size();
    vector<int>ldp(size, 0);
    vector<int>rdp(size, 0);
    // 填写当前ldp中当前数左边的G的个数
    int l = 0;
    for (int i = 0; i<size; ++i)
    {
        ldp[i] = l;
        if (str[i] == 'G')
            ++l;
    }
    // 填写当前rdp中当前数右边的R的个数
    int r = 0;
    for (int i = size - 1; i >= 0; --i)
    {
        rdp[i] = r;
        if (str[i] == 'R')
            ++r;
    }
    // 开始计算
    int res = 100;
    for (int i = 0; i<size; ++i)
    {
        if (ldp[i] + rdp[i] < res)
            res = ldp[i] + rdp[i];
    }
    cout << res << endl;
    return 0;
}