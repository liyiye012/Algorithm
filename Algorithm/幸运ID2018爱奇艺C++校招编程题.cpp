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

using namespace std;

void output(vector<int> arr) {
    for (auto a : arr) {
        cout << a << " ";
    }cout << endl;
}
/*
����ID
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 131072KB���������� 655360KB
��Ŀ������
СC��һ��Ʊ������Ʊ��ID�ǳ���Ϊ6���ַ�����ÿ���ַ��������֣����������ID�����������ID���������Ϳ�ʼ����ID��ÿһ�β�����������ѡ������һ�����ֲ����滻����

������ID��ǰ��λ����֮�͵��ں���λ����֮�ͣ���ô���ID�������˵ġ����СC��һ�£�������Ҫ�������Σ���ʹID�������ID

����
����ֻ��һ�У���һ������Ϊ6���ַ�����

���
��������С��������


��������
000000
�������
0

Hint
��������2
000018

�������2
1

�������ͣ���ǰ��λ����һ����Ϊ9��������������������Ϊ1
��ܰ��ʾ*/
int solve(vector<int> n) {
    int cor =2;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 3; i++) sum1 += n[i];
    for (int j = 3; j < 6; j++) sum2 += n[j];

    // To Do

    return cor;
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