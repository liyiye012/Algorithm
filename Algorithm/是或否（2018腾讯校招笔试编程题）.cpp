/*
��Ŀ����

������������ABC�������ѡ�����ɸ����֣�������Щ���ֱ�����A�ı������������ٵ�ѡ��һ�����֡�

���Ƿ����һ��ѡ�񷽰�ʹ����Щ���ֵĺͶ�Bȡ��Ľ��ΪC���������YES�������NO

��������

�������t(1<=t<=20),ABC(1<=ABC<100)

�������

���YES��NO

ʾ��1

sample input

3
91 16 5
58 16 0
96 12 4

sample output

YES
YES
NO
��˼·������һ�������RP����Ȼ���ˣ���̨����ˮ��~����Ŀǰû���뵽���õķ�����
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 233;
int T, n, m, q;
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &q);
        int sum = 0;
        int v = 1;
        int k = 0;
        bool ok = false;
        for (int i = 1; i <= N; ++i)
        {
            if (i*n%m == q)
            {
                ok = true;
                break;
            }
            if (i == N && i*n%m != q)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}