/*
题目描述

小Q在学校学习了最小公倍数的求法：

LCM（2）=2，LCM（4,6）=12，LCM（1,2,3,4,5,6）=60

现在给出一个正整数n，求计算出最小的大于n的正整数m，使得满足：LCM(n+1,n+2,,m)=LCM(1,2,,m)

例如：n=3，那么m=6,因为LCM（4,5,6）=LCM（1,2,3,4,5,6）=60并且这个m是最小的大于n的正整数。

输入描述

输入包括一个正整数n（1<=n<=1e6）

输出描述

输出m

示例1

sample input

3

sample output

6

【思路】

做完之后，网上搜了一下原来有原题，下面是我觉得写得还不错的题解

假设有质数K，可以求出t，使得K的t次方刚好小于等于m（K^t<=m），
那么lcm(1,2,…,m)分解质因数中一定而且最多有t个质数K连乘，
其实我们可以就是求的质数的最高次幂，这样就可以很快地把lcm(1,2,…,m)分解质因数，
那么怎么把 lcm(n+1,n+2,…,m)分解质因数呢？我们仍然假设质数K，
可以求出最大的t，以及一个常数c（1<=c < K)，
使得 n+1<=cK^t<=m 那么lcm(n+1,n+2,…,m)分解质因数中一定而且最多有t个质数K连乘。
比如说质数3，n=16,m=22,可以求的c=2,t=2，即17<=23^2=18<=22，
这样lcm(17,18,19,20,21,22)中最多有2个质数3连乘，
既然知道怎么求lcm(n+1,n+2,..,m)和lcm(1,2,..,m)了，
接下来探讨一下怎么求最小的m，我们想让这两个lcm分解质因数后完全一样，
也就是说连乘的质数个数也完全相等。也就是说，对于每个质数K都可以满足，
存在c和最大的t 使得n+1<=cK^t<=m对于大于n小于m的质数，我们假设是P，
那么一定n+1<=P<=m，一定可以满足条件所以我们就只看小于等于n的质数就可以了因为要使每个小于N的质数K，
都存在c和最大的t 使得n+1<=cK^t<=m，我们枚举每一个质数，并求得c和t，使得刚好cK^t>=n， 
答案就取最大的cK^t，即 max( c*K^t )这样lcm(1,2,…,m)和lcm(n+1,n+2,…,m)的分解质因数后均至少有t个质数K。
如果最终m有 k^(t+1)<=m，那么这个K^(t+1)>n一定成立，故仍满足条件。

参考：https://blog.csdn.net/guhaiteng/article/details/53014576
*/
#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 2e6 + 233;
bool prime[N];//质数为0非质数为1
long long cnt[N];//存储第i个质数
int T, n, m, num;

void getPrim(long long v)
{
    long long  m = sqrt(v + 0.5);
    memset(prime, 0, sizeof(prime));//可以根据情况进行清空操作
    num = 0;//把找到的质数存入数组中，num为数组的长度
            //如果要获得质数数组，i就枚举到size，如果仅仅是prim数组，就枚举到m
    for (long long i = 2; i <= v; i++)
    {
        if (!prime[i])
        {
            cnt[++num] = i;
            if (i <= m)
                for (long long j = i*i; j <= v; j += i)
                    prime[j] = 1;
        }
    }
}

int getMinLcm(int n)
{
    getPrim(n);
    long long ans = n + 1;
    long long j;
    for (long long i = num; i >= 1; --i)
    {
        long long  k = cnt[i];
        for (j = 1; j*k <= n; j *= k);
        ans = max(ans, (n / j + 1)*j);
    }
    return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d", &n);
    printf("%d\n", getMinLcm(n));
    return 0;
}



//我的解法 20% ac
//#include <iostream>
//#include <string>
//#include <vector>
//#include <ctime>
//#include <set>
//#include <map>
//#include <unordered_map>
//#include <queue>
//#include <algorithm>
//#include <cmath>
//
//
//#include<functional>
//using namespace std;
//void output(vector<int> arr) {
//    for (auto a : arr) {
//        cout << a << " ";
//    }cout << endl;
//}
//int gcd(long long x, long long y)
//{
//    while (x != y)
//    {
//        if (x>y) x = x - y;
//        else
//            y = y - x;
//    }
//    return x;
//}
//
//int twogcd(long long x, long long y) {
//    return x / gcd(x, y) *y;
//}
//
//int solve(long long n) {
//    long long s = 1;
//    s = 1 / gcd(1, 2) * 2;
//    //cout << "LCM(n)=" << s << endl;
//    for (long long i = 2; i<=n; i++) {
//        s = (s / gcd(s, i))*i;
//       // cout << "LCM(n)=" << s <<"   i="<<i<< endl;
//    }
//    //cout << "LCM(n)=" << s << endl;
//    long long m = n + 1;
//    long long ss = (n + 1) / gcd(n + 1, n + 1) *(n + 1);
//    while (ss != s) {
//       
//        s = (s / gcd(s, m)) *m;
//        ss = (ss / gcd(ss, m)) *m;
//        //cout << "LCM(m)=" << s << "   m=" << m << "   LCM(n+1,m)=" << ss << endl;
//        m++;
//    }
//    return m-1;
//}
//int main() {
//    long long n;
//    cin >> n;
//    cout << solve(n);
//
//    return 0;
//}