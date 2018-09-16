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

/*
题目描述

小Q所在的王国有n个城市，城市之间有m条单向道路连接起来。

对于一个城市V，从城市V出发可以到达的城市数量为X，从某个城市出发可以达到城市V的城市数量为Y，如果Y>X ，则城市V是一个重要城市（间接到达也算可以到达）。

小Q希望你能帮他计算一下王国中一共有多少个重要城市。

输入描述

输入包括m+1行

第一行包括两个数n和m（1<=n,m<=1000）,分别表示城市数和道路数

接下来m行，每行两个数u,v(1<=u,v<=n)，表示一条从u到v的有向道路，输入可能包含重边和自环

输出描述

输出一个数，重要节点的个数。

示例1

sample input
4 3
2 1
3 2
4 3
sample output
2

城市1,2是重要城市
*/
bool judge(const pair<int, int> a, const pair<int, int> b) {
    if (a.first == b.first) return a.second<b.second;
    else return a.first<b.first;
}

int solve(vector<pair<int, int>> route, int n, int m) {
    int node=0;
    for (int i = 1; i <= route.size(); i++) { //对所有路线中的城市进行遍历计算入度和出度
        int in = 0;
        int out = 0;
        for (int j = 0; j<route.size(); j++) {
            if (route[j].first == i) out++;
            else if (route[j].second == i) in++;
        }
        if (in>out) node++;
    }
    return node;
}
int main() {
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> route;
    int u, v;
    for (int i = 0; i<m; i++) {
        cin >> u >> v;
        route.push_back(make_pair(u, v)); //存储路线
    }
    for (int i = 0; i<m; i++) {  //针对路线可能存在的环进行更新
        for (int j = i + 1; j<m; j++) {
            if (route[i].second == route[j].first) {
                route.push_back(make_pair(route[i].first, route[j].second));
            }
            else if (route[j].second == route[i].first) {
                route.push_back(make_pair(route[j].first, route[i].second));
            }
        }
    }
    cout << route.size() << endl;
    cout << solve(route, n, m);
    return 0;
}

/*【思路】数据范围1e3,不是很大，考虑统计每个城市的入度和出度，就是一个简单的深度优先遍历了
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+233;
vector<int>G[N];
int from[N],to[N],vis[N];
int n,m,cnt,ans;

void dfs(int x)
{
if(vis[x]) return;//当前城市已经访问返回
vis[x]=1;//标记当前城市已经访问
cnt++;//从当前城市i出发每次访问下一个城市结点贡献出度
from[x]++;//每次访问当前城市，贡献一次入度
for(int i=0; i<(int)G[x].size(); ++i)
{
int next=G[x][i];
dfs(next);
}
}

void init()
{
for(int i=1; i<=n; ++i)
G[i].clear();
memset(from,0,sizeof(from));
memset(to,0,sizeof(to));
}

void io()
{
scanf("%d%d",&n,&m);
for(int i=0; i<m; ++i)
{
int s,t;
scanf("%d%d",&s,&t);
G[s].push_back(t);
}
}

void solve()
{
for(int i=1; i<=n; ++i)//对于每一个城市，深度优先遍历它的下一个城市
{
memset(vis,0,sizeof(vis));
cnt=0;
dfs(i);
to[i]=cnt;
}
ans=0;
for(int i=1; i<=n; ++i)//对于每一个城市，如果入度大于出度，贡献一个答案
{
if(from[i]>to[i]) ++ans;
}
printf("%d\n",ans);
}

int main()
{
//freopen("in.txt","r",stdin);
init();
io();
solve();
}
/*
sample input
4 3
2 1
3 2
4 3
sample output
2
*/
*/