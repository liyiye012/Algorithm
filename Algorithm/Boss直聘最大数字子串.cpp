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
bool isnum(char c) {
    if ((c - '0' >= 0) && ('9' - c >= 0)) return true;
    else return false;
}
void solve(string para) {
    int i = 0;
    int number = 0;
    int maxnum = 0;
    while (i < para.size()) {
        if ((isnum(para[i]) == false)) {
            //cout << "meet unalpha i=" << i << "   temp=" << temp << endl;
            maxnum = max(number, maxnum);
            number = 0;
        }
        else {
            number = number * 10 + (para[i] - '0');
        }
        maxnum = max(number, maxnum);
        i++;
    }
    cout << maxnum;
}
int main() {
    //freopen("in.txt", "r", stdin);
    string para;
    cin >> para;
    solve(para);


    return 0;
}