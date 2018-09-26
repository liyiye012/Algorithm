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
/*
    ����n֧����������һ��ֱ���ϣ��������ҵ�i֧���������Ϊxi����֤Xi-1<Xi������֤������������
    ��ʼ״̬������û�б���ȼ������Ҫ��ȼ���е�K֧����
    ����������=0��λ���ϣ���������������ƶ������ȼK֧������Ҫ�߶�����С����

    �����һ��Ϊn,K
    �ڶ�������x1,x2,...,xn

    ���Ϊ��С����
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <map>
#include <set>
#include <climits>

using namespace std;
//other people's binary solution
int binary(vector<long long>& data, int key) {
    int l = 0;     
    int r = data.size();    
    while (l + 1 < r) { 
        int mid = (l + r) / 2;         
        if (data[mid] <= key) { l = mid; } 
        else { r = mid; } }     
    return l;
}
//my binarysearch 
//i want to compare this to other people's  binary solution
int binarysearch(vector<long long> &data, int key) {
    int l = 0;
    int r = data.size() - 1;
    while (l < r) {
        int mid = l + (r - l) >> 1;
        if (data[mid] < key) {
            l = mid+1;
        }
        else if(data[mid] > key){
            r = mid-1;
        }
        else return mid;
    }
    return l;
}
int main() {
    freopen("in.txt", "r", stdin);
    long long n, k, x;    
    vector<long long> data;     
    scanf("%lld%lld", &n, &k);     
    for (int i = 0; i < n; i++) { 
        scanf("%lld", &x);         
        data.push_back(x); }     
    //int p = binary(data, 0);
    int p = binarysearch(data, 0); //find the start index
    // cout <<  p << endl;     
    long long res = LLONG_MAX;     
    for (long long i = p-k > 0 ? p-k : 0; i+k-1 <= n-1; i ++) {// start from the possible start index
        long long temp = 0;         
        long long start = data[i];         
        long long end = data[i+k-1];         
        // cout << start << " " << end << endl;         
        if(end < 0) {             
            temp = (0-start);         }
        else if (start < 0 && end > 0){             
            temp = min((0-start)*2 + end, 2*end + (0-start));         
        }else if (start > 0) {             
            temp = end;         
        }

        // cout << temp << endl;         
        if (temp < res) {            
            res = temp;         
        }     
    }     
    cout << res << endl;     
    return 0;
}
