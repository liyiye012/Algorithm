#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
链接：https://www.nowcoder.com/questionTerminal/b96da2bd7a574699b4ceaaa7819cf65b
来源：牛客网

牛牛养了n只奶牛,牛牛想给每只奶牛编号,这样就可以轻而易举地分辨它们了。 每个奶牛对于数字都有自己的喜好,第i只奶牛想要一个1和x[i]之间的整数(其中包含1和x[i])。
牛牛需要满足所有奶牛的喜好,请帮助牛牛计算牛牛有多少种给奶牛编号的方法,输出符合要求的编号方法总数。
输入描述:
输入包括两行,第一行一个整数n(1 ≤ n ≤ 50),表示奶牛的数量 第二行为n个整数x[i](1 ≤ x[i] ≤ 1000)


输出描述:
输出一个整数,表示牛牛在满足所有奶牛的喜好上编号的方法数。因为答案可能很大,输出方法数对1,000,000,007的模。
示例1
输入
4
4 4 4 4
输出
24


解析：对输入的x[i]值进行从小到大排序，每只牛能够编成的号数其实就为想x[i]-i。代码如下：


*/
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> vec(n, 0);
        for (int i = 0; i<n; ++i)
            cin >> vec[i];
        sort(vec.begin(), vec.end());
        long long sum = 1;
        for (int i = 0; i<n; ++i)
        {
            sum *= (vec[i] - i);
            sum %= 1000000007;
        }
        cout << sum << endl;
    }
    return 0;
}
