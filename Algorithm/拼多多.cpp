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
bool isaplhachar(char c) {
    if (((c - 'a' >= 0) && (c - 'z' <= 0))  || ((c - 'A' >= 0) && (c - 'Z' <= 0))) return true;
    else return false;
 }
void solve(string para) {
    map<string, int> mp;
    int i = 0;
    int start = i, end = i;
    string temp = "";
    while (i < para.size()) {
        cout << "i=" << i << endl;
        if ((isaplhachar(para[i]) == false) ) {
            cout << "meet unalpha i=" << i << "   temp=" << temp << endl;
            if(temp.size()>0) mp[temp]++;
            temp = "";
        }
        else {
            temp += para[i];
            cout << "alpha i=" << i << "   temp=" << temp << endl;
        } 
        i++;
    }
    if (mp.size() == 1) for (auto m : mp) cout << m.second;
    else {
        
        for (int i = 1; i < mp.size(); i++) {

        }
    }
    cout << mp.size() << endl;
}
int main() {
    //freopen("in.txt", "r", stdin);
    if (isaplhachar(' ') == false) cout << "false"<<endl;
    else cout << "True" << endl;
    string para;
    cin >> para;
    solve(para);


    return 0;
}