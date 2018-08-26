#include <iostream>
#include<unordered_map>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack> 
#include <functional> 
#include<set>
using namespace std;
void output(vector<int> Arr) {
    for (int i = 0; i < Arr.size(); i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
}
 
inline bool isodd(int num) {
    return num & 0x1 == 1;
}
 
void erase_one(std::multiset<long long> &s, long long x) {
    auto it = s.find(x);
    auto it1 = it;
    it1++;
    s.erase(it, it1);//����ҿ���ɾ������itָ���Ԫ��
}
/*���̿�����Ϊ��θ�ˡ����˻�����Ӫ���ɷ֣����������ڹ���ǰʳ�ã����ҿ��ܺܿ����!���⣬��ͬ�����̻��ڲ�ͬ�����ӹ��ڡ�
¶����ϲ�����̣���������N�����̣����������Լ������޷������̹���ǰȫ�����ꡣ�ӽ��쿪ʼ����i�����̻���ڣ��ڹ��ڵ����֮����κ�һ�춼���ܺȡ�
��Ȼ¶����ϲ�����̣�����ÿ�����ֻ�ܺ�K�����̡��ӽ��쿪ʼ��������ܺȶ��ٱ�����?
����
����ĵ�һ�и�������������������T T�����������¡�ÿ������������һ�п�ʼ�����а�����������N��K������������Ȼ�󣬻���һ��N������Ai������������
���
����ÿ���������������һ�а���case #x: y������x�ǲ���������(��1��ʼ)��y��Lucy���Ժȵ����ļ������̣�����������Yogurt can be a nutritious part of an appetizer, main course, or dessert, but it must be consumed before it expires, and it might expire quickly! Moreover, different cups of yogurt might expire on different days.

Lucy loves yogurt, and she has just bought N cups of yogurt, but she is worried that she might not be able to consume all of them before they expire. The i-th cup of yogurt will expire Ai days from today, and a cup of yogurt cannot be consumed on the day it expires, or on any day after that.

As much as Lucy loves yogurt, she can still only consume at most K cups of yogurt each day. What is the largest number of cups of yogurt that she can consume, starting from today?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with one line containing two integers N and K, as described above. Then, there is one more line with N integers Ai, as described above.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum number of cups of yogurt that Lucy can consume, as described above.

Limits
1 �� T �� 100.
1 �� K �� N.
1 �� Ai �� 109, for all i.
Small dataset
1 �� N �� 1000.
K = 1.
Large dataset
1 �� N �� 5000.
Sample

Input 
 	
Output 
 
4
2 1
1 1
5 1
3 2 3 2 3
2 2
1 1
6 2
1 1 1 7 7 7

Case #1: 1
Case #2: 3
Case #3: 2
Case #4: 5

Note that the last two sample cases would not appear in the Small dataset.

In Sample Case #1, each of the two cups of yogurt will expire in one day. Today, Lucy can consume one of them, but she can only consume at most one cup each day, so she cannot consume both. Tomorrow, Lucy cannot consume the remaining cup of yogurt, because it will have expired.

In Sample Case #3, Lucy can consume up to two cups each day, so she can consume all of the yogurt.*/
void solve1() {// brute force TLE
    int N = 0, K = 0;
    cin >> N >> K;
    vector<int> a; 
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp; 
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
  /*  cout << "a[N-1]=" << a[N - 1] << "  "; 
    cout << "After sort:   "; output(a);*/
    
    int num = 0;
    int maxday = a[N - 1];
    for (int i = 0; i < maxday; i++) {//error i < a[N - 1] ��Ϊa[N-1]�ᶯ̬�仯
       // cout << "i=" << i << "  ";
        int k = 0;
        for (int j = 0; j < N ; j++) {
        //    cout << "j=" << j << endl;
            if ((a[j] > 0)&&(k<K)) {
                a[j] = 0;
                k++;
                num++;
            }
        }
       // cout << "  num=" << num<<"  "; output(a);
        for (int mm = 0; mm < N; mm++) { a[mm] -= 1; }
        
    }
    cout << num << endl;
}
void solve2() {// brute force TLE
    int N = 0, K = 0;
    cin >> N >> K;
    vector<int> a;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    
    int num = 0;
        int maxday = a[N - 1];
        for (int i = 0; i < maxday; i++) {//error i < a[N - 1] ��Ϊa[N-1]�ᶯ̬�仯
            //cout << "i=" << i << "  ";    
            int k = 0;
            vector<int>::iterator nonezeroindex = lower_bound(a.begin(), a.end(), 1);
            for (int j = nonezeroindex-a.begin(); j <nonezeroindex - a.begin()+ K && j<N ; j++) {
                a[j] = 0;
                num++;            
            }
            //cout << "  nonezeroindex="<<(nonezeroindex-a.begin())<<"  num=" << num<<"  "; output(a);
            for (int mm = nonezeroindex - a.begin(); mm < N; mm++) { a[mm] -= 1; }
            
        }
    cout << num << endl;
}
void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N+1,0);
    for (int i = 1; i <= N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int  num=0;
    for (int k = 1, i = 1; i <= N; k++) {
        int j = min(i + K, N + 1);
        num += j - i;
        i = j;
        for (; i <= N && a[i] <= k; i++);
    }
    cout << num << endl;
}

int main() {
    freopen("C:\\Users\\yiye\\Downloads\\A-small-attempt0.in", "r", stdin);
    //freopen("C:\\Users\\yiye\\Downloads\\out.txt", "w", stdout);
    //freopen("out.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        //if (i == 2 || i == 25 || i == 28 || i == 32 || i == 44 || i == 64 || i == 97) { cout << "0" << endl; continue; }
        solve();

    }
        //===========================
        //fclose(stdin);//�ر��ļ� 
        //fclose(stdout);//�ر��ļ� 
        return 0;
    } 