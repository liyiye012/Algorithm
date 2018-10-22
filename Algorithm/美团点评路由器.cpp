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
void output(vector<int> arr) {
    for (auto a : arr) {
        cout << a << " ";
    }cout << endl;
}
void solve() {
    int n,k;
    cin >> n>>k;
    
    int temp = 0;
 
    //


    vector<int> arr(n, 1);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        int left = i - 1;
        int leftsig = temp;
        while (left >= 0 && leftsig>0) {
            arr[left]++;
            left--;
            leftsig--;
        }
        int right = i + 1;
        int rightsig =temp;
        while (right < n && rightsig > 0) {
            arr[right]++;
            right++;
            rightsig--;
        }
        // output(arr);
       
    }
   
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= k) res++;
    }
    cout <<res;
}
int main() { 
  //  freopen("in.txt", "r", stdin);
    solve();
    return 0;
}