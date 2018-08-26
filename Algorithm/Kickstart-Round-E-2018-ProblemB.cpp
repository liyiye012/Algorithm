#include <iostream>
#include<unordered_map>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
#include<set>
#include<bitset>
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
/*�й����̲�ܺóԡ������̲��кܶ��Ԫ(�Ǵ˼���)ѡ����硰�ӱ���/�����ӱ����������ǡ�/�������ǡ����������ݡ�/���������ݡ������Ӳ�����/�����Ӳ������ȵȡ��˿Ͷ��̲��ϲ�ÿ�����һ���������ַ�����ʾ�����磬ʹ��������������(��˳������)���ַ���1100��ʾ���ӱ������ǡ��������ݡ����Ӳ�������
���죬ɳ����Ҫ��һ���ṩ��Ԫѡ����̵���Ϊ����N������ÿ����һ���̲衣�������ռ���ÿ���˵�ϲ�ú�Shakti���ֶ������̫�����ˣ�����Shakti����Ϊÿ���˹�����ͬ���͵��̲衣ɯ�˵�֪��������ÿһ�����ѣ�����ÿһ���������ƫ�ã����Ƕ��ᱧԹһ�Ρ����磬����������Ѷ�101��010������ƫ�ã���Shaktiѡ����001���ͣ���ô��һ�����ѻᱧԹһ�Σ��ڶ������ѻᱧԹ���Σ��ܹ�������Ͷ�ߡ�
���⣬��M�ֲ�ͬ�Ľ��̲裬���̲�������ShaktiҲ�޷�ѡ���κ�һ�ֽ��̲衣
ɳ�����ܵõ���Ͷ�������Ƕ���?
����
����ĵ�һ�и�������������������T T�����������¡�ÿ�����������԰���3������N��M��P���п�ʼ������������Ȼ�󣬻���N���У�ÿһ�ж�����һ���������ַ���;��Щ������N�����ѵ�ϲ�á���󣬻���M���У�ÿһ�ж�����һ���������ַ���;��Щ�������̲��̵겻�������Ľ������͡��������ַ�������0��/��1���ַ���ɡ�
���
����ÿ���������������һ�а���case #x: y������x�ǲ���������(��1��ʼ)��y��Shakti�������������Ĺ����ܹ��õ�����СͶ��������

�ڰ���1�У���3�����ѣ�������Ҫ1100�ͣ�1010�ͺ�0000�͵��̲衣���Shakti����ѡ������1000����ôÿ�����ѻᱧԹһ�Σ��ܹ�3�Ρ�Ȼ��������1000���̵��ǲ����õġ���ˣ�����ЩԼ�������£����ŵĽ��������ѡ��1100�͡�Ȼ���������ѻ�ֱ�Ͷ��0�Ρ�2�κ�2�Σ��ܹ�Ͷ��4�Ρ�
��ʾ������#2�У�Shakti�����ѡ����ѡ������1110��ÿ�����ѻᱧԹһ�Σ��ܹ�2�Ρ�ע�⣬��ͬ�����ѿ�������ͬ��ƫ�á���Ҫע�⣬���۴�С���ݼ������ƶ���֤��������һ�ֿ��ܵ��̲������ǲ�����ֹ�ġ�
The milk tea in China is very delicious. There are many binary ("either-or") options for customizing a milk tea order, such as "with ice"/"no ice", "with sugar"/"no sugar", "with bubbles"/"no bubbles", "with pudding"/"no pudding", and so on. A customer's preferences for their milk tea can be represented as a binary string. For example, using the four properties above (in the order they are given), the string 1100 means "with ice, with sugar, no bubbles, no pudding".

Today, Shakti is on duty to buy each of his N friends a milk tea, at a shop that offers P binary options. But after collecting everyone's preferences, Shakti found that the order was getting too complicated, so Shakti has decided to buy the same type of milk tea for everyone. Shakti knows that for every friend, for every preference that is not satisfied, they will complain once. For example, if two of the friends have preferences for types 101 and 010, and Shakti chooses type 001, then the first friend will complain once and the second friend will complain twice, for a total of three complaints.

Moreover, there are M different forbidden types of milk tea that the shop will not make, and Shakti cannot choose any of those forbidden types.

What is the smallest number of complaints that Shakti can get?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line containing 3 integers N, M, and P, as described above. Then, there are N more lines, each of which contains a binary string; these represent the preferences of the N friends. Finally, there are M more lines, each of which contains a binary string; these represent the forbidden types of milk tea that the shop will not make. Binary strings consist only of 0 and/or 1 characters.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum number of complaints that Shakti can get, per the rules described above.

Limits
1 �� T �� 100.
All of the forbidden types of milk tea are different.
Small dataset
1 �� N �� 10.
1 �� M �� min(10, 2P - 1).
1 �� P �� 10.
Large dataset
1 �� N �� 100.
1 �� M �� min(100, 2P - 1).
1 �� P �� 100.
Sample

Input 
 	
Output 
 
2
3 1 4
1100
1010
0000
1000
2 4 4
1111
1111
1111
0111
1011
1101

Case #1: 4
Case #2: 2

In Sample Case #1, there are 3 friends, and they want milk teas of types 1100, 1010, and 0000. If Shakti could choose type 1000, then each friend would complain once, for a total of 3 complaints. However, type 1000 is not available in the shop. So, given these constraints, an optimal solution is to choose type 1100. Then, his friends will complain 0, 2, and 2 times, respectively, for a total of 4 complaints.

In Sample Case #2, Shakti's best option is to choose type 1110. Each friend will complain once, for a total of 2 complaints. Notice that different friends might have the same preferences. Also notice that the limits for both the Small and Large datasets guarantee that there is always at least one possible type of milk tea that is not forbidden.*/
void solve() {
     
}

int main() {
    freopen("C:\\Users\\yiye\\Downloads\\A-small-attempt0.in", "r", stdin);
    //freopen("C:\\Users\\yiye\\Downloads\\out.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        solve();

    }
    //===========================
    //fclose(stdin);//�ر��ļ� 
    //fclose(stdout);//�ر��ļ� 
    return 0;
}