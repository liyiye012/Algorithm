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
https://blog.csdn.net/flushhip/article/details/79416715
��һ�⣺�û�ϲ��



��Ŀ��


Ϊ�˲����Ż��Ƽ�Ч��������ͷ��ÿ��Ҫ�洢�ʹ��������ݡ�����������һ�ֳ��������Ƕ��û��������ǵ�ע��ʱ���Ⱥ�����ţ�����һ�����£�ÿ���û����в�ͬ��ϲ��ֵ�����ǻ���֪��ĳһ��ʱ����ע����û������������һ���û����У��ж����û�����������ϲ��ֵΪkkk����ΪһЩ�����ԭ�򣬲������һ����ѯ���û�������ȫ������һ����ѯ���û�����(������L1<=L2<=R2<=R1L1<=L2<=R2<=R1L_1<=L_2<=R_2<=R_1)��




���룺


��1��Ϊn�����û��ĸ��� ��2��Ϊn����������i�������û����Ϊi���û���ĳ�����µ�ϲ�ö� ��3��Ϊһ��������q�����ѯ������, ��4�е���(3+q)�У�ÿ�а���3������l,r,k����һ���ѯ�������Ϊl<=i<=r���û��ж���������ϲ��ֵΪk���û��ĸ����� ���ݷ�Χn<=300000,q<=300000n<=300000,q<=300000n <= 300000,q<=300000��k�����͡�




�����


һ��q�У�ÿ��һ����������ϲ��ֵΪk���û��ĸ�����




�������룺

5
1 2 3 3 5
3
1 2 1
2 4 5
3 5 3




���������

1
0
2




����

���ݺܴ�ѯ��300000�Σ���ôÿ��ѯ�ʶ�Ӧ�Ĳ�����ʱ�临�Ӷȱ�����O(1)O(1)O(1)��O(logn)O(logn)O(logn)��

���Ϊ����˼���㷨�ṩ�˷���O(1)O(1)O(1)��Ȼ�ǲ����ܵģ���ô������ʱ�临�Ӷ�ΪO(logn)O(logn)O(logn)���㷨ֻ���Ƕ��ֲ����ˣ���ˣ�������ʱ�临�Ӷ����뵽���ֲ��ң���ô�������Ͳ���������ˣ�

���ֵ�Ҫ��������������˲�����ô�࣬�����򣬿��ǰ���ʲô�����������أ�������ĿҪ����һ��ʱ�䷶Χ��ϲ��Ϊk���ж����ˣ���ô���԰���ͬkֵ���˷ŵ�һ���γ�һ�������У�Ȼ���ٸ���ʱ��ķ�Χ������������в��ң�����ýṹ��Ķ��������Ȱ�kֵ�Ĵ�С�����������kֵ��ͬ���ٰ�ʱ��˳����������

*/

bool sort_cmp(const pair<int, int> &A, const pair<int, int> &B)
{
    return A.first == B.first ? A.second < B.second :
        A.first < B.first;
}

struct find_first_cmp {
    bool operator()(const pair<int, int> &P, int k) const
    {
        return P.first < k;
    }

    bool operator()(int k, const pair<int, int> &P) const
    {
        return k < P.first;
    }
};

struct find_second_cmp {
    bool operator()(const pair<int, int> &P, int k) const
    {
        return P.second < k;
    }

    bool operator()(int k, const pair<int, int> &P) const
    {
        return k < P.second;
    }
}; 
int main() {
    int n, q;
    while (EOF != scanf("%d", &n)) {
        vector<pair<int, int> > arr;
        for (int i = 0, x; i < n; cin >> x, arr.emplace_back(x, ++i)) {}
        sort(arr.begin(), arr.end(), sort_cmp);

        for (scanf("%d", &q); q--;) {
            int L, R, k;
            scanf("%d%d%d", &L, &R, &k);
            pair<vector<pair<int, int> >::iterator, vector<pair<int, int> >::iterator> sd =
                equal_range(arr.begin(), arr.end(), k, find_first_cmp{});
            printf("%d\n", upper_bound(sd.first, sd.second, R, find_second_cmp{}) -
                lower_bound(sd.first, sd.second, L, find_second_cmp{}));
        }
    }
    return 0; 
}