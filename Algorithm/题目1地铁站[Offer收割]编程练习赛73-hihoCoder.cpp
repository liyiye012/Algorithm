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
//using namespace std;
////#define vi vector<int>
////#define pii pair<int,int>
////#define x first
////#define y second
////#define all(x) x.begin(),x.end()
////#define pb push_back
////#define mp make_pair
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
//void solve(vector<int> X, int N, int K) {
//    int num = 0;
//    num %= mod;
//    cout << "No" << endl;
//}
//int main() { 
//    freopen("in.txt", "r", stdin);
//   // freopen("out.txt", "w", stdout);
//    int N,K;
//    cin >> N >> K;
//    vector<int> X;
//    for (int i = 0; i < N-K; i++) {
//        int temp = 0;
//        cin >> temp;
//        X.push_back(temp);
//    }
//    solve(X,N,K);
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

int a[N];
int main() {
    //cout<<setprecision(9)<<fixed;
    int T, j, i, k, ca = 0, m = 0, K, n;
    scanf("%d%d", &n, &K);
    m = n - K;
    rep(i, 0, m)scanf("%d", &a[i]);
    int sz = 0;
    rep(i, 0, m) {
        K -= a[i] - 1;
        j = i + 1;
        while (j<m&&a[j]>a[j - 1])K -= a[j] - a[j - 1] - 1, j++;
        if (K<0)break;
        sz++; i = j - 1;
    }
    if (K<0) {
        puts("No"); return 0;
    }
    ll x = 1;
    rep(i, sz, K + sz)x = x*i%mod;
    ll y = 1;
    rep(i, 1, K + 1)y = y*i%mod;
    x = x*pow((int)y, mod - 2) % mod;
    printf("%lld\n", x);
}