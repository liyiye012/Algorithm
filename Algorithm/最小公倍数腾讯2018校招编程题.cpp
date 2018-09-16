/*
��Ŀ����

СQ��ѧУѧϰ����С���������󷨣�

LCM��2��=2��LCM��4,6��=12��LCM��1,2,3,4,5,6��=60

���ڸ���һ��������n����������С�Ĵ���n��������m��ʹ�����㣺LCM(n+1,n+2,,m)=LCM(1,2,,m)

���磺n=3����ôm=6,��ΪLCM��4,5,6��=LCM��1,2,3,4,5,6��=60�������m����С�Ĵ���n����������

��������

�������һ��������n��1<=n<=1e6��

�������

���m

ʾ��1

sample input

3

sample output

6

��˼·��

����֮����������һ��ԭ����ԭ�⣬�������Ҿ���д�û���������

����������K���������t��ʹ��K��t�η��պ�С�ڵ���m��K^t<=m����
��ôlcm(1,2,��,m)�ֽ���������һ�����������t������K���ˣ�
��ʵ���ǿ��Ծ��������������ߴ��ݣ������Ϳ��Ժܿ�ذ�lcm(1,2,��,m)�ֽ���������
��ô��ô�� lcm(n+1,n+2,��,m)�ֽ��������أ�������Ȼ��������K��
�����������t���Լ�һ������c��1<=c < K)��
ʹ�� n+1<=cK^t<=m ��ôlcm(n+1,n+2,��,m)�ֽ���������һ�����������t������K���ˡ�
����˵����3��n=16,m=22,�������c=2,t=2����17<=23^2=18<=22��
����lcm(17,18,19,20,21,22)�������2������3���ˣ�
��Ȼ֪����ô��lcm(n+1,n+2,..,m)��lcm(1,2,..,m)�ˣ�
������̽��һ����ô����С��m����������������lcm�ֽ�����������ȫһ����
Ҳ����˵���˵���������Ҳ��ȫ��ȡ�Ҳ����˵������ÿ������K���������㣬
����c������t ʹ��n+1<=cK^t<=m���ڴ���nС��m�����������Ǽ�����P��
��ôһ��n+1<=P<=m��һ���������������������Ǿ�ֻ��С�ڵ���n�������Ϳ�������ΪҪʹÿ��С��N������K��
������c������t ʹ��n+1<=cK^t<=m������ö��ÿһ�������������c��t��ʹ�øպ�cK^t>=n�� 
�𰸾�ȡ����cK^t���� max( c*K^t )����lcm(1,2,��,m)��lcm(n+1,n+2,��,m)�ķֽ����������������t������K��
�������m�� k^(t+1)<=m����ô���K^(t+1)>nһ����������������������

�ο���https://blog.csdn.net/guhaiteng/article/details/53014576
*/
#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 2e6 + 233;
bool prime[N];//����Ϊ0������Ϊ1
long long cnt[N];//�洢��i������
int T, n, m, num;

void getPrim(long long v)
{
    long long  m = sqrt(v + 0.5);
    memset(prime, 0, sizeof(prime));//���Ը������������ղ���
    num = 0;//���ҵ����������������У�numΪ����ĳ���
            //���Ҫ����������飬i��ö�ٵ�size�����������prim���飬��ö�ٵ�m
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



//�ҵĽⷨ 20% ac
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