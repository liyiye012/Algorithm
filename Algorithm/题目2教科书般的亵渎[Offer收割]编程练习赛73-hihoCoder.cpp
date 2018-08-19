//#include <iostream>
//#include <string>
//#include <stdio.h>
//#include <string.h>
//#include <vector>
//#include <ctime>
//#include <set>
//#include <map>
//#include <unordered_map>
//#include <queue>
//#include <algorithm>
//#include <cmath>
//#include <assert.h>
//
//using namespace std;
////#define vi vector<int>
//#define pii pair<int,int>
////#define x first
////#define y second
////#define all(x) x.begin(),x.end()
////#define pb push_back
//#define mp make_pair
////#define SZ(x) x.size()
////#define rep(i,a,b) for(int i=a;i<b;i++)
////#define per(i,a,b) for(int i=b-1;i>=a;i--)
////#define pi acos(-1)
//#define mod 1000000007
////#define inf 1000000007
////#define ll long long
////#define DBG(x) cerr<<(#x)<<"="<<x<<"\n";
////#define N 1000010
//////#define _DEBUG
////template <class U, class T> void Max(U &x, T y) { if (x<y)x = y; }
////template <class U, class T> void Min(U &x, T y) { if (x>y)x = y; }
////template <class T> void add(int &a, T b) { a = (a + b) % mod; }
////
////int pow(int a, int b) {
////    int ans = 1;
////    while (b) {
////        if (b & 1)ans = 1LL * ans*a%mod;
////        a = 1LL * a*a%mod; b >>= 1;
////    }
////    return ans;
////}
////
////int pow(int a, int b, int c) {
////    int ans = 1;
////    while (b) {
////        if (b & 1)ans = 1LL * ans*a%c;
////        a = 1LL * a*a%c; b >>= 1;
////    }
////    return ans;
////}
//void output(vector<int> arr) {
//    for (auto a : arr) {
//        cout << a << " ";
//    }cout << endl;
//}
//void attack(pair<pii,bool> &hi, pair<pii, bool> &ho) {
//    hi.first.second -= ho.first.first;
//    ho.first.second -= hi.first.first;
//    hi.first.second = true;// has already attacked
//}
//void insult(vector<pair<pii, bool>> &hi, vector<pair<pii, bool>> &ho) {
//    bool realease = false;
//    for (auto h : hi) {
//        if (h.first.second == 1) realease = true;
//        h.first.second--;
//    }
//    for (auto h : ho) {
//        if (h.first.second == 1) realease = true;
//        h.first.second--;
//    }
//    if (realease) insult(hi, ho);
//}
//bool checkdead(vector<pair<pii, bool>> ho) {
//    bool dead = true;//全灭为真，否则为假
//    for(auto h:ho){
//        if (h.first.second > 0) return false;
//    }
//    return dead;
//}
//void solve() {
//    int  M, N;
//    cin >> N >> M;
//    vector<pair<pii,bool>> Hi, Ho;
//    for (int i = 0; i < N; i++) {
//        int x = 0, y = 0;
//        cin >> x >> y;
//        Hi.push_back(mp(mp(x, y),false));
//    }
//    for (int i = 0; i < M; i++) {
//        int x = 0, y = 0;
//        cin >> x >> y;
//        Ho.push_back(mp(mp(x, y), false));
//    }
//    cout << "Yes" << endl;
//
//}
//int main() {
//    //freopen("in.txt", "r", stdin);
//    // freopen("out.txt", "w", stdout);
//    int T;
//    cin >>T ; 
//    for (int i = 0; i <T; i++) {
//        solve();
//    }
//    
//    return 0;
//}
#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <assert.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define SZ(x) x.size()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define pi acos(-1)
#define mod 1000000007
#define inf 1000000007
#define ll long long
#define DBG(x) cerr<<(#x)<<"="<<x<<"\n";
#define N 200010
#define _DEBUG

template <class T, class U>inline void Max(T &a, U b) { if (a<b)a = b; }
template <class T, class U>inline void Min(T &a, U b) { if (a>b)a = b; }
inline void add(int &a, int b) { a += b; while (a >= mod)a -= mod; }


int pow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1)ans = ans*(ll)a%mod;
        a = (ll)a*a%mod; b >>= 1;
    }
    return ans;
}

pii a[7], b[7];
int sz = 0, s[13], now, q[8], n, m;
int dfs(int x) {
    if (x == sz) {
        int mx = 0; now++;
        rep(i, 0, m)if (b[i].y>0)s[b[i].y] = now, Max(mx, b[i].y);
        if (mx == 0)return 1;
        rep(i, 0, n)if (a[i].y>0)s[a[i].y] = now;
        rep(i, 1, mx)if (s[i] != now)return 0;
        return 1;
    }
    int j = q[x];
    rep(i, 0, m)if (b[i].y>0) {
        a[j].y -= b[i].x;
        b[i].y -= a[j].x;
        int ret = dfs(x + 1);
        a[j].y += b[i].x;
        b[i].y += a[j].x;
        if (ret)return 1;
    }
    return 0;
}
int main() {
    //cout<<setprecision(9)<<fixed;
    int T, j, i, k, ca = 0, K;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        rep(i, 0, n)scanf("%d%d", &a[i].x, &a[i].y);
        rep(i, 0, m)scanf("%d%d", &b[i].x, &b[i].y);
        int ok = 0;
        rep(i, 0, (1 << n)) {
            sz = 0;
            rep(j, 0, n)if (i >> j & 1) {
                q[sz++] = j;
            }
            if (dfs(0)) {
                ok = 1; break;
            }
        }
        puts(ok ? "YES" : "NO");
    }
}
