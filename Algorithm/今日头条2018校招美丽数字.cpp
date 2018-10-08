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

*/
//inline bool checkis(int a, int b, int nn) {
//
//}
bool checkinclude(int a, int b, long long n) {
    bool inc = true;
    while (n) {
        long long t = n % 10;
        if ( t!= a && t!= b) inc = false;
        n /= 10;
    }
    return inc;
}
bool checksum(int a,int b,long long n) {
    long long sum = 0;
    while (n) {
        sum += n % 10; 
        n /= 10;
    }
    if (checkinclude(a, b, sum)) return true;
    else return false;
}
void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    long long high = 1;
    for (int i = 0; i < k; i++) {
        high *= 10;
    }
    long long low = high / 10;
   // cout << high << endl;
    int num = 0;
    for (long long i = low; i <= high; i++) {
       // cout << "i=" << i << endl;
        if ( checksum(a, b, i) && checkinclude(a, b, i)) num++;
       // cout << num << endl;
        num %= 1000000007;
    }
    cout<<num;
}
int main() {
    //freopen("in.txt", "r", stdin);
    solve();
    return 0;
}