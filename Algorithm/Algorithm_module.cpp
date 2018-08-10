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
#define N 1000010
#define _DEBUG
template <class U, class T> void Max(U &x, T y) { if (x<y)x = y; }
template <class U, class T> void Min(U &x, T y) { if (x>y)x = y; }
template <class T> void add(int &a, T b) { a = (a + b) % mod; }

int pow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1)ans = 1LL * ans*a%mod;
        a = 1LL * a*a%mod; b >>= 1;
    }
    return ans;
}

int pow(int a, int b, int c) {
    int ans = 1;
    while (b) {
        if (b & 1)ans = 1LL * ans*a%c;
        a = 1LL * a*a%c; b >>= 1;
    }
    return ans;
}
void output(vector<int> arr) {
    for (auto a : arr) {
        cout << a << " ";
    }cout << endl;
}
void solve() {

}
int main() {
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}