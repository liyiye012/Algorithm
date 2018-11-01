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
#include<sstream>

using namespace std;
void output(vector<int> arr) {
    cout << "size=" << arr.size() << endl;
    for (auto a : arr) {
        cout << a << endl;
    }cout << endl;
}




int main() {
    freopen("in.txt", "r", stdin);
    string str;
    cin >> str;
    int i = 0;
    stringstream sStream;
    int arr[18];
    int pos = str.find(',');
    while (pos != string::npos) {
        str = str.replace(pos, 1, 1, ' ');
        pos = str.find(',');
    }
    sStream << str;
    while (sStream) {
        sStream >> arr[i++];
    }
    vector<int> num;
    for (int j = 0; j < 18; j++) {
        num.push_back(arr[j]);
    }
    sort(num.begin(), num.end());
    output(num);
    return 0;
}