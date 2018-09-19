#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#define ll long long
#define maxn 2005
#define mod 1000000007
using namespace std;
/*
����С��
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
�����������͵�С��P��Q��R��ÿ��С��������ֱ�Ϊnp��nq��nr���������뽫��ЩС���ų�һ��ֱ�ߣ����ǲ�������ͬ���͵�С�����ڣ����ж��������з���������np=2��nq=1��nr=1����6�����з�ʽ��PQRP��QPRP��PRQP��RPQP��PRPQ�Լ�PQPR�� ����޷���ϳ����ʵĽ���������0��

����
һ���Կո���������������ֱ��ʾΪnp��nq��nr��

���
���з�����������


��������
2 1 1
�������
6

*/

ll n, q, x, sum, cur;
ll a[maxn], fac[maxn], c[maxn][maxn], f[3][maxn];

void Pre() {
    fac[0] = 1;
    for (int i = 1; i <= n; i++)fac[i] = 1ll * i*fac[i - 1] % mod;
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        c[i][0] = c[i][i] = 1;
    }
    return;
}

void solve() {
    int np, nq, nr;
    cin >> np >> nq >> nr;
    cout << np + nq + nr;
}
int main() {
    //freopen("in.txt", "r", stdin);
    /*solve();*/
    cin >> n >> q;
    n = 3;
    for (int i = 1; i <= n; i++) a[i] = gi();
    Pre();
    sum = 0; cur = 0;
    f[cur][0] = 1;
    for (int i = 1; i <= n; i++) {
        cur ^= 1;
        for (int t = 0; t <= a[i] + sum + 1; t++)
            f[cur][t] = 0;
        for (int k = 1; k <= a[i] && k <= sum + 1; k++)
            for (int j = 0; j <= sum; j++)
                for (int l = 0; l <= k && l <= j; l++) {
                    f[cur][j - l + a[i] - k] +=
                        1ll * f[cur ^ 1][j] * c[a[i] - 1][k - 1] % mod*(1ll * c[j][l] * c[sum + 1 - j][k - l] % mod) % mod;
                    f[cur][j - l + a[i] - l] %= mod;
                }
        sum += a[i];
    }
    cout << f[cur][0];

    return 0;
}