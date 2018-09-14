#include<iostream>
#include<vector>
using namespace std;
bool check(long long num) {
    bool flag = false;
    if (num >= 10 && (num % 10) == ((num / 10) % 10)) flag = true;
    return flag;
}
int solve(int L, int R) {
    long long  cnt = 0;
    for (long long i = L; i <= R; i++) {
        if (i == R) cout << "i=" << i << endl;
        if (check(i)) { cnt++; 
        
        }
    }
    return cnt;
}
int main() {
    long long L, R;
    cin >> L >> R;
    cout << solve(L, R);
    return 0;
}