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
��Ŀ����

СQ���ڵ�������n�����У�����֮����m�������·����������

����һ������V���ӳ���V�������Ե���ĳ�������ΪX����ĳ�����г������Դﵽ����V�ĳ�������ΪY�����Y>X �������V��һ����Ҫ���У���ӵ���Ҳ����Ե����

СQϣ�����ܰ�������һ��������һ���ж��ٸ���Ҫ���С�

��������

�������m+1��

��һ�а���������n��m��1<=n,m<=1000��,�ֱ��ʾ�������͵�·��

������m�У�ÿ��������u,v(1<=u,v<=n)����ʾһ����u��v�������·��������ܰ����رߺ��Ի�

�������

���һ��������Ҫ�ڵ�ĸ�����

ʾ��1

sample input
4 3
2 1
3 2
4 3
sample output
2

����1,2����Ҫ����
*/
bool judge(const pair<int, int> a, const pair<int, int> b) {
    if (a.first == b.first) return a.second<b.second;
    else return a.first<b.first;
}

int solve(vector<pair<int, int>> route, int n, int m) {
    int node=0;
    for (int i = 1; i <= route.size(); i++) { //������·���еĳ��н��б���������Ⱥͳ���
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
        route.push_back(make_pair(u, v)); //�洢·��
    }
    for (int i = 0; i<m; i++) {  //���·�߿��ܴ��ڵĻ����и���
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

/*��˼·�����ݷ�Χ1e3,���Ǻܴ󣬿���ͳ��ÿ�����е���Ⱥͳ��ȣ�����һ���򵥵�������ȱ�����
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+233;
vector<int>G[N];
int from[N],to[N],vis[N];
int n,m,cnt,ans;

void dfs(int x)
{
if(vis[x]) return;//��ǰ�����Ѿ����ʷ���
vis[x]=1;//��ǵ�ǰ�����Ѿ�����
cnt++;//�ӵ�ǰ����i����ÿ�η�����һ�����н�㹱�׳���
from[x]++;//ÿ�η��ʵ�ǰ���У�����һ�����
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
for(int i=1; i<=n; ++i)//����ÿһ�����У�������ȱ���������һ������
{
memset(vis,0,sizeof(vis));
cnt=0;
dfs(i);
to[i]=cnt;
}
ans=0;
for(int i=1; i<=n; ++i)//����ÿһ�����У������ȴ��ڳ��ȣ�����һ����
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