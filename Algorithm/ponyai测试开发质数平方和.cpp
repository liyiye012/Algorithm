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
using namespace std; 
/*
����ƽ����
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
����������N (N <= 1000)���������С�ڵ���N��������ƽ���͡�

����
һ��һ��������N

���
һ��һ������������ʾ����С�ڵ���N��������ƽ����


��������
5
�������
38

Hint
2^2+3^2+5^2=38
��ܰ��ʾ
�뾡����ȫ�����Խ���10����ǰ���Գ��򣬷��������ܼ��Ŷ��ύ�����ܲ�ѯ����������
��������ԡ���ɱ������
��������ʹ�ñ��ر���������ҳ�治��¼��������
*/
bool prime(int num) {
    bool flag = true;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num%i == 0) {
            flag = false;
        }
    }
    return flag;
}
void solve() {
    int N;
    cin >> N;
    int sum = 0;
    for (int i = 2; i <= N; i++) {
        if (prime(i)) sum = sum + (i*i);
    }
    cout << sum;
}
int main() {
    //freopen("in.txt", "r", stdin);
    solve();




    return 0;
}