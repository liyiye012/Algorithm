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
�ֳ���ʳ��
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 131072KB���������� 655360KB
��Ŀ������
�ֳ���N��ʳ�ÿ��ʳ����Ai�ݡ�

ÿ��ֳ����һ��ʳ�������һ��ʳ���ÿ��ֻ�ܽ��гԻ������е�һ�ֶ���������������M��

���ھֳ���֪��M����p��ʳ��ķ����������Ӵ�С����ͬ�㲢�У�����3 3 2��������Ϊ1 1 3��

N,M,P<=100,Ai<=1000

����
��һ��N M P

�ڶ���N����Ai

������M�У�ÿ��A i����B i�ֱ��ʾ��һ��ʳ��i����һ��ʳ��i

���
һ����


��������
3 4 2
5 3 1
B 1
A 2
A 2
A 3
�������
1


����ͨ��64%
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