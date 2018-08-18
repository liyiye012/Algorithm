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
/*今天我们看到的阿里巴巴提供的任何一项服务后边都有着无数子系统和组件的支撑，子系统之间也互相依赖关联，
其中任意一个环节出现问题都可能对上游链路产生影响。小明做为新人接收到的第一个任务就是去梳理所有的依赖关系，
小明和每个系统的负责人确认了依赖关系，记录下调用对应系统的耗时，用这些数据分析端到端链路的数目和链路上最长的耗时。

输入： 小明搜集到的系统耗时和依赖列表
5  4   // 表示有5个系统和 4个依赖关系
3      // 调用1号系统耗时 3 ms
2      // 调用2号系统耗时 2 ms
10     // 调用3号系统耗时 10 ms
5      // 调用4号系统耗时 5 ms
7      //  调用5号系统耗时 7 ms
1 2    //  2号系统依赖1号系统
1 3    //  3号系统依赖1号系统
2 5    //  2号系统依赖5号系统
4 5    //  4号系统依赖5号系统

输出:  调用链路的数目 和最大的耗时， 这里有三条链路1->2->5，1->3， 4->5，最大的耗时是1到3的链路 3+10 = 13，无需考虑环形依赖的存在。
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
    //unordered_map<int, int> depend;  //error :不应该使用unordered_map存储因为会使得相同开始点的路径被覆盖
    //for (int j = 0; j < dep; j++) {
    //    int d1 = 0;
    //    int d2 = 0;
    //    cin >> d1 >> d2;
    //    depend[d1] = d2;
    //}
    vector<vector<int>> depend;  //error :不应该使用unordered_map存储因为会使得相同开始点的路径被覆盖
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