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
    ���û���ϵͳ�����û����������δʹ�ù�����ϵͳ���û����������ݿⲢ���ء�OK����ʾע��ɹ���
    ���û���username�Ѿ����������ݿ���ϵͳ�Զ������µ��û�����������뵽���ݿ���ͬʱ���ظ��û���
    ���û������ɹ������Ѿ����ڵ��û���username֮��׷������1��2��3...��username1��username2����ÿ�ζ�Ѱ����С��û���ù������ֿ�ʼ׷��
    �ָ���n���û�ע����������ÿ��ϵͳ���ص��ַ���

    ����������
    ��һ��һ������n��ʾע������ĸ���
    ����n��ÿ��һ���ַ�����ʾ�û�����ȫ����Сд��ĸ���
*/
//pass 30%
unordered_map<string, int> name;
vector<vector<string>> namevec;
void solve() {
    string s;
    cin >> s;
    if (name.find(s) == name.end()) {
        cout << "OK" << endl;
        name[s] = 1;
    }
    else {
        string news = "";
        news += s;
        news+=('0' + name[s]);
        
        name[s]++;
        name[news]=1;
        cout << news << endl;
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}

//�ο������о�����
//#include <iostream>
//#include <cstdio>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <unordered_set>
//#include <cmath>
//#include <map>
//
//using namespace std;
//
//int main() {
//    freopen("in.txt", "r", stdin);
//    map<string, int> dict;     
//    string s;     
//    int n;     
//    scanf("%d", &n);     
//    for (int i = 0; i < n; i++) { 
//        cin >> s;         
//        if (dict.find(s) == dict.end()) { 
//            dict[s] = 0;             
//            cout << "OK" << endl; } 
//        else { dict[s] += 1;             
//        cout << s + to_string(dict[s]) << endl;
//        } 
//    }     
//    return 0;
//}