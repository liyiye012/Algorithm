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
 ��Сдת��
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
����һ������ĸ��������ɵ��ַ������뽫���еĴ�д��ĸת����Сд�����Сд��ĸת���ɴ�д����������ַ�����

����
һ��һ������ĸ��������ɵ��ַ��������Ȳ�����100

���
һ��һ������ĸ��������ɵ��ַ���


��������
IlovePonyAI666
�������
iLOVEpONYai666
*/
bool ischaracter(string str,int i) {
    bool is = false;
    char c = str[i];
    if (((c - 'a' >= 0) && (c - 'z' <= 0)) || ((c - 'A' >= 0) && (c - 'Z' <= 0))) is = true;
     return is;
}
void solve() {
    string str;
    cin >> str;
    string res = "";
    for (int i = 0; i < str.size(); i++) {
        if (ischaracter(str,i)) {
            //cout << "ischar" << endl;
            if ((str[i] - 'a' >= 0) && (str[i] - 'z' <= 0)) {
                res += 'A' + (str[i] - 'a');
            }
            else if ((str[i] - 'A' >= 0) && (str[i] - 'Z' <= 0)) {
                res += 'a' + (str[i] - 'A');
            }
        }

        else { 
            //cout << "isnumber" << endl;
            res += str[i]; 
        }

        //cout << "i="<<i<<"    "<<res << endl;
    }
    cout << res;
}
int main() {
    //freopen("in.txt", "r", stdin);
    solve();




    return 0;
}