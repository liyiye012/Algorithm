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

using namespace std;

void output(vector<int> arr) {
    for (auto a : arr) {
        cout << a << " ";
    }cout << endl;
}
/*
局长的食物
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 131072KB；其他语言 655360KB
题目描述：
局长有N种食物，每种食物有Ai份。

每天局长会吃一份食物，或者买一份食物（即每天只能进行吃或买其中的一种动作），这样过了M天

现在局长想知道M天后第p种食物的份数排名（从大到小，相同算并列，例如3 3 2，则排名为1 1 3）

N,M,P<=100,Ai<=1000

输入
第一行N M P

第二行N个数Ai

接下来M行，每行A i或者B i分别表示买一份食物i，吃一份食物i

输出
一个答案


样例输入
3 4 2
5 3 1
B 1
A 2
A 2
A 3
样例输出
1


本答案通过64%
*/

int main() {
    int N, M, P;
    cin >> N >> M >> P;
    vector<int> A(N,0);
    int t;
    
    for (int i = 0; i < N; i++) { cin >> t; A[i] = t; }


    
    for (int i = 0; i < M; i++) {
        char action;
        int index ;
        cin >> action >> index;
       // cout << action << index;
        if (action == 'A') A[index-1] ++;
        else if (action == 'B') A[index-1]--;
    }
    
    int num = A[P-1];
    sort(A.begin(), A.end());
  //output(A);
    int paiming=1;
    if(N==1) cout << paiming;
    else {
        for (int i = N - 1; i >= 0; i--) {
            //cout << " before i=" << i << "   paiming=" << paiming << endl;
            while ( (i>0) && (A[i] == A[i - 1] )) i--;
           // cout << "Running1";
            if (A[i] == num) { //cout << "Running2";
                break; }
            else if (A[i] > num) { //cout << "Running3";
            paiming++; }
           // cout << "end i=" << i << "   paiming=" << paiming << endl;
        }
        
        cout << paiming;
    }

    return 0;
}