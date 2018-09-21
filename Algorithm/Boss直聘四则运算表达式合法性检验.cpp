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
#include<stack>
using namespace std;
bool isnum(char c) {
    if ((c - '0' >= 0) && ('9' - c >= 0)) return true;
    else return false;
}
bool isoperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') return true;
    else return false;
}
bool checkkuo(string str) {
    stack<char> small;
    for (int i = 0; i<str.size(); i++)
    {
        switch (str[i])
        {
        case '(': small.push(str[i]);//遇到‘（’压进去
            break;
        case ')': if (!small.empty())
        {
            small.pop(); //遇到‘）’弹出来
            break;
        }
                   if (small.empty()) //循环问结束，若此时为空则失配，
                       break;
        }
    }
    if (small.empty()) //循环结束后，此时为空则匹配
        return true;
    else
        return false;

}
void solve(string s) {
    bool check = true;
    if (!checkkuo(s)) check = false;
    if (s.size() == 0) check = false;
    if (s[0] == '+' || s[0] == '*' || s[0] == '/') check = false;
    if (s[s.size()-1] == '+' || s[s.size() - 1] == '*' || s[s.size() - 1] == '/') check = false;

    for (int i = 1; i < s.size() - 1; i++) {
        if (isoperator(s[i - 1]) && isoperator(s[i]))  check = false;
        if (isoperator(s[i ]) && isoperator(s[i+1]))  check = false;
        if (s[i]=='/' && s[i+1]=='0' )  check = false;

    }

    if (check) cout << "True";
    else cout << "False";
}
int main() {
    //freopen("in.txt", "r", stdin);
    string s;
    cin >> s;
    solve(s);


    return 0;
}