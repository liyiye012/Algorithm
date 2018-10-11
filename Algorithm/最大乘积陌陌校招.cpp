#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;
/*
���˻�
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
�г���Ϊn���������飬���� n �������а���˳��ѡȡm����Ҫ����������������ԭ�����е�λ��������i��ʹ���� m �������ĳ˻�����뷵�����˻���

����
��һ�� ����n ��1<n<20��

�ڶ��� ��˳���n������   �����ķ�Χ��-50 �� 50֮��

������ ����i��m  ��1<i<20, 1<m<50)

���
���س˻�


��������
3
7 4 7
2 50
�������
49

*/
//inline bool checkis(int a, int b, int nn) {
//
//}
const int N = 110;
const long long inf = 1e16;
long long a[N], mx[N][15], mn[N][15];
void solve() { 
    //int n;
    //cin >> n;
    //vector<int> num;
    //int temp;
    //for (int i = 0; i < n; i++) {
    //    cin >> temp;
    //    num.push_back(temp);
    //}
    //int i, m;
    //cin >> i >> m;
    //
    int n;
    while (scanf("%d", &n) > 0) {
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        int d, m;
        scanf("%d%d", &m, &d);
        for (int i = 1; i <= n; i++) {
            mx[i][0] = 1;
            mn[i][0] = 1;
            for (int j = 1; j <= m; j++) {
                mx[i][j] = -inf;
                mn[i][j] = inf;
            }
        }
        long long mmx = -100, mmn = 100;
        long long ans = -inf;
        for (int i = 1; i <= n; i++) {
            mmx = max(mmx, a[i]);
            mx[i][1] = a[i];
            mn[i][1] = a[i];
            if (m == 1)ans = max(ans, mmx);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= m && j <= i; j++) {
                for (int k = i - 1; k >= max(1, i - d) && k >= j - 1; k--) {
                    mx[i][j] = max(mx[i][j], mx[k][j - 1] * a[i]);
                    mx[i][j] = max(mx[i][j], mn[k][j - 1] * a[i]);
                    mn[i][j] = min(mn[i][j], mn[k][j - 1] * a[i]);
                    mn[i][j] = min(mn[i][j], mx[k][j - 1] * a[i]);
                    if (j == m)ans = max(ans, mx[i][j]);
                }
            }
        }
        printf("%lld\n", ans);
    }

}
int main() {
    //freopen("in.txt", "r", stdin);
    solve();
    return 0;
}