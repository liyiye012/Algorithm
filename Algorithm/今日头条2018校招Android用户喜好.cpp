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
第一题：用户喜好



题目：


为了不断优化推荐效果，今日头条每天要存储和处理海量数据。假设有这样一种场景：我们对用户按照它们的注册时间先后来标号，对于一类文章，每个用户都有不同的喜好值，我们会想知道某一段时间内注册的用户（标号相连的一批用户）中，有多少用户对这类文章喜好值为kkk。因为一些特殊的原因，不会出现一个查询的用户区间完全覆盖另一个查询的用户区间(不存在L1<=L2<=R2<=R1L1<=L2<=R2<=R1L_1<=L_2<=R_2<=R_1)。




输入：


第1行为n代表用户的个数 第2行为n个整数，第i个代表用户标号为i的用户对某类文章的喜好度 第3行为一个正整数q代表查询的组数, 第4行到第(3+q)行，每行包含3个整数l,r,k代表一组查询，即标号为l<=i<=r的用户中对这类文章喜好值为k的用户的个数。 数据范围n<=300000,q<=300000n<=300000,q<=300000n <= 300000,q<=300000，k是整型。




输出：


一共q行，每行一个整数代表喜好值为k的用户的个数。




样例输入：

5
1 2 3 3 5
3
1 2 1
2 4 5
3 5 3




样例输出：

1
0
2




解析

数据很大，询问300000次，那么每次询问对应的操作的时间复杂度必须是O(1)O(1)O(1)或O(logn)O(logn)O(logn)；

这就为我们思考算法提供了方向，O(1)O(1)O(1)显然是不可能的，那么操作的时间复杂度为O(logn)O(logn)O(logn)的算法只能是二分查找了，因此，你从这个时间复杂度联想到二分查找，那么这个题你就差不多做出来了；

二分的要求是序列有序，因此不管那么多，先排序，可是按照什么东西来排序呢？由于题目要求在一个时间范围内喜好为k的有多少人，那么可以把相同k值的人放到一起形成一个子序列，然后再根据时间的范围在这个子序列中查找，因此用结构体的二级排序，先按k值的大小升序排序，如果k值相同，再按时间顺序升序排序；

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