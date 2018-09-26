#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <map>
#include <set>

using namespace std;
/*
    ��˾����Щ�豸����ͬһ��ţ���Щ�豸��ų������ڱ�����䣬��1-n��ѡ�����ְ�������
    ���б�ţ�������Ҫ��ı��������ģ��ظ��ı�ű�����һ�γ��ֵ��豸��ţ����ĵı�ű�������
    �ָ���n̨�豸�ı�ţ���n̨�豸��������Ҫ�����±��

    ��һ����������豸��n
    �ڶ��к���n��������a1,a2,...,an��ʾ��ǰ�豸���
*/
int main() {
    freopen("in.txt", "r", stdin);
    int n, x;
    vector<int> data, vis;
    set<int> s;//set �Ǵ�С�����Զ��ź�������򼯺�
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        data.push_back(x);
        s.insert(i + 1);
        vis.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        if (s.find(data[i]) != s.end()) {//ȥ�ظ�������
            vis[i] = 1;
            s.erase(data[i]);
        }
        else { vis[i] = 0; }
    }
    //for (auto a : s) cout << a << " "; cout << endl;
    for (int i = 0; i < n; i++) { //��������1-n��û���ֹ��ı�ŷ�����豸
        if (vis[i] == 0) {
            // cout << i << " ";             
            data[i] = *s.begin();
            s.erase(*s.begin());
        }
    }     // cout << endl;     
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;

}