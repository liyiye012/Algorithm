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


#include<functional>
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

//̰���㷨+˫ָ��
/*���ߣ�ccccccccccccccc
���ӣ�https://www.nowcoder.com/discuss/109903
��Դ��ţ����

˼· : ǰ��������һ�����飬����������һ�����顣�����������Ͳ���ȣ���ô�����Ļ���˼·���£�Ҫô��С�����е���Сֵ����Ҫô���������е����ֵ��С�������ǵ������飬���ǵ�С���飬ȡ���� ���ֵ����Сֵ�ܵ����ķ��ȡ�
*/
int dif(vector<int> arr1, vector<int> arr2, int num) {
    sort(arr1.begin(), arr1.end());
    arr1.push_back(INT_MIN);
    sort(arr2.begin(), arr2.end(),std::greater<int>()); //�Ӵ�С������Ҫ #include<functional>
    arr2.push_back(INT_MAX);

    int i = 0;
    int j = 0;
    int c = 0;

    while (num > 0) {
        int cur1 = arr1[i];
        int cur2 = arr2[j];
        int val = 0;
        if (9 - cur1 > cur2 - 0) {
            val = 9 - cur1;
            j++;
        }else{
            val = cur2 - 0;
            i++;
        }
        if (val > num) num = 0;
        else num -= val;
        c++;
    }
    return c;
}
int solve(vector<int> n) {
    int sum1 = 0, sum2 = 0;
    vector<int> num1, num2;
    for (int i = 0; i < 3; i++) { 
        num1.push_back(n[i]);
        sum1 += n[i]; 
    }
    for (int j = 3; j < 6; j++) { 
        num2.push_back(n[j]);
        sum2 += n[j]; 
    }
 
    // To Do
    int res = 0;
    if (sum1 < sum2) res = dif(num1, num2, sum2 - sum1);
    else res = dif(num2, num1, sum1 - sum2);
    

    return res;
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