#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
/*
���ӣ�https://www.nowcoder.com/questionTerminal/7442938f5012486499ddd61ce16f9086
��Դ��ţ����

���һ������������������,���Ǿͳ���Ϊ������:
1�����������������λ
2��������������λ����ͬ��
����: 1488��һ��������,��3��112���ǡ�
ţţ���ڸ���һ��һ������[L,R],�����������������ж��ٸ�������
��������:
�����������������L��R(1 �� L �� R �� 10^12),�Կո�ָ


�������:
���һ��������,�������ڵ��������ĸ�����
ʾ��1
����
10 20
���
1
*/

int main() {
    string s;
    int r[55], g[55];
    while (cin >> s) {
        r[0] = g[0] = 0;
        for (int i = 0; i<s.size(); i++) {
            if (s[i] == 'R') {
                r[i + 1] = r[i] + 1;
                g[i + 1] = g[i];
            }
            else {
                r[i + 1] = r[i];
                g[i + 1] = g[i] + 1;
            }
        }
        ///ͳ��R��G������
        int sumR = r[s.size()];
        int sumG = g[s.size()];
        ///���������ǰ�Rȫ��ΪG���߰�Gȫ����ΪR
        int res = min(sumR, sumG);
        for (int i = 1; i <= s.size(); i++) {
            ///����ÿ������Ҫ�޸ĵ���������¼��Сֵ����
            res = min(res, g[i] + sumR - r[i]);
        }
        cout << res << endl;
    }
    return 0;
}
