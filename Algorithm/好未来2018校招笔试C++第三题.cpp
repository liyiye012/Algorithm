#include<vector>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<cstdio>
using namespace std;
class Solution {
public:
 
    void solve(vector<int> num,vector<string> & s, int index) { 
    }
};
/*
�����λ���µ�������������

��Ŀ������
���ڹ̶�����{0��1��2��3��4��5��6��7��8��9}
���벼������{0��1��1��1��1��1��1��1��1��0}
����0��ʾ��Ӧ�±�����Ԫ�ؿɳ���Ҳ���Բ����֣�1��ʾ�������������п�������ϣ�ת�����ַ������������ַ�����������
012345678
0123456789
12345678
123456789

����������
λ�ó��ֵĲ���ֵ

���������
��ӡ�������

˼·����������ĵѿ�����
*/
int main() {
    vector<string> arr;
    int a[11];
    for (int i = 0; i<10; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i<(1 << 10); i++)
    {
        int f = 0;
        for (int j = 0; j<10; j++)
            if (!((i&(1 << j))) && a[j])
            {
                f = 1;
                break;
            }
        if (f)
            continue;
        string str = "";
        for (int j = 0; j<10; j++)
            if (i&(1 << j))
                str.push_back('0' + j);
        arr.push_back(str);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i<arr.size(); i++)
        cout << arr[i] << endl;
    return 0;
    return 0;
}