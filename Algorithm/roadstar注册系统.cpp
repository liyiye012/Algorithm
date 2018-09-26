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
    新用户向系统发送用户名，如果是未使用过的则系统将用户名插入数据库并返回“OK”表示注册成功；
    若用户名username已经存在于数据库中系统自动生成新的用户名并将其插入到数据库中同时返回给用户；
    新用户名生成规则在已经存在的用户名username之后追加数字1，2，3...（username1，username2），每次都寻找最小的没有用过的数字开始追加
    现给出n个用户注册的请求，输出每次系统返回的字符串

    输入描述：
    第一行一个整数n表示注册请求的个数
    下面n行每行一个字符串表示用户名，全部由小写字母组成
*/
//pass 30%
unordered_map<string, int> name;
vector<vector<string>> namevec;
void solve() {
    string s;
    cin >> s;
    if (name.find(s) == name.end()) {
        cout << "OK" << endl;
        name[s] = 1;
    }
    else {
        string news = "";
        news += s;
        news+=('0' + name[s]);
        
        name[s]++;
        name[news]=1;
        cout << news << endl;
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}

//参考，但感觉不对
//#include <iostream>
//#include <cstdio>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <unordered_set>
//#include <cmath>
//#include <map>
//
//using namespace std;
//
//int main() {
//    freopen("in.txt", "r", stdin);
//    map<string, int> dict;     
//    string s;     
//    int n;     
//    scanf("%d", &n);     
//    for (int i = 0; i < n; i++) { 
//        cin >> s;         
//        if (dict.find(s) == dict.end()) { 
//            dict[s] = 0;             
//            cout << "OK" << endl; } 
//        else { dict[s] += 1;             
//        cout << s + to_string(dict[s]) << endl;
//        } 
//    }     
//    return 0;
//}