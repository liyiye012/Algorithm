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
/*�������ǿ����İ���Ͱ��ṩ���κ�һ������߶�����������ϵͳ�������֧�ţ���ϵͳ֮��Ҳ��������������
��������һ�����ڳ������ⶼ���ܶ�������·����Ӱ�졣С����Ϊ���˽��յ��ĵ�һ���������ȥ�������е�������ϵ��
С����ÿ��ϵͳ�ĸ�����ȷ����������ϵ����¼�µ��ö�Ӧϵͳ�ĺ�ʱ������Щ���ݷ����˵�����·����Ŀ����·����ĺ�ʱ��

���룺 С���Ѽ�����ϵͳ��ʱ�������б�
5  4   // ��ʾ��5��ϵͳ�� 4��������ϵ
3      // ����1��ϵͳ��ʱ 3 ms
2      // ����2��ϵͳ��ʱ 2 ms
10     // ����3��ϵͳ��ʱ 10 ms
5      // ����4��ϵͳ��ʱ 5 ms
7      //  ����5��ϵͳ��ʱ 7 ms
1 2    //  2��ϵͳ����1��ϵͳ
1 3    //  3��ϵͳ����1��ϵͳ
2 5    //  2��ϵͳ����5��ϵͳ
4 5    //  4��ϵͳ����5��ϵͳ

���:  ������·����Ŀ �����ĺ�ʱ�� ������������·1->2->5��1->3�� 4->5�����ĺ�ʱ��1��3����· 3+10 = 13�����迼�ǻ��������Ĵ��ڡ�
3  13   */
void output(vector<int> arr) {
    for (auto a : arr) {
        cout << a << " ";
    }cout << endl;
}
void maxtime(unordered_map<int, int> time, vector<vector<int>> res){
    int maxtime=0;
    for (int i = 0; i < res.size(); i++) {
        int localtime = 0;
        for (int j = 0; j < res[i].size(); j++) {
            localtime += time[res[i][j]];
        }
        maxtime = max(maxtime, localtime);
    }
    cout << "  "<<maxtime;
}

void solve() {
    int S = 0;
    int dep = 0;
    cin >> S >> dep;
    unordered_map<int, int>  time;
    for (int i = 1; i <= S; i++) {
        int temp = 0;
        cin >> temp;
        time[i] = temp;
    }
    //unordered_map<int, int> depend;  //error :��Ӧ��ʹ��unordered_map�洢��Ϊ��ʹ����ͬ��ʼ���·��������
    //for (int j = 0; j < dep; j++) {
    //    int d1 = 0;
    //    int d2 = 0;
    //    cin >> d1 >> d2;
    //    depend[d1] = d2;
    //}
    vector<vector<int>> depend;  //error :��Ӧ��ʹ��unordered_map�洢��Ϊ��ʹ����ͬ��ʼ���·��������
    for (int j = 0; j < dep; j++) {
        vector<int> temp;
        int d1 = 0;
        int d2 = 0;
        cin >> d1 >> d2;
        temp.push_back(d1);
        temp.push_back(d2);
        depend.push_back(temp);
    }
    //cout << "depend.size=" << depend.size() << endl;
    vector<vector<int>> res;
    vector<int> visited;
    for (int i = 0;i< depend.size();i++) {
        vector<int>::iterator findnum = find(visited.begin(), visited.end(), i);
        if (findnum != visited.end()) continue;
        vector<int> temp;
        temp.push_back(depend[i][0]);
        temp.push_back(depend[i][1]);
        for (int j = i+1;j< depend.size();j++) {
            if (depend[j][0]== temp[temp.size()-1]) {
                temp.push_back(depend[j][1]);
                visited.push_back(j);
            }            
        }
        res.push_back(temp);
        //output(temp);
    }
    //output
    //cout << "res=" << endl;
    //for (auto r : res) {
    //    output(r);
    //}
    cout << res.size();
    maxtime(time, res);
}
int main() {
    //freopen("in.txt", "r", stdin);
    solve();
    return 0;
}