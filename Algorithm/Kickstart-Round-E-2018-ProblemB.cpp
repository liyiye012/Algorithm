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
    s.erase(it, it1);//左闭右开，删除的是it指向的元素
}
/*中国的奶茶很好吃。定制奶茶有很多二元(非此即彼)选项，比如“加冰”/“不加冰”、“加糖”/“不加糖”、“加泡泡”/“不加泡泡”、“加布丁”/“不加布丁”等等。顾客对奶茶的喜好可以用一个二进制字符串表示。例如，使用上述四种属性(按顺序排列)，字符串1100表示“加冰、加糖、不加气泡、不加布丁”。
今天，沙克提要在一家提供二元选择的商店里为他的N个朋友每人买一杯奶茶。但是在收集了每个人的喜好后，Shakti发现订单变得太复杂了，所以Shakti决定为每个人购买相同类型的奶茶。莎克蒂知道，对于每一个朋友，对于每一个不满意的偏好，他们都会抱怨一次。例如，如果两个朋友对101和010类型有偏好，而Shakti选择了001类型，那么第一个朋友会抱怨一次，第二个朋友会抱怨两次，总共有三个投诉。
此外，有M种不同的禁奶茶，店铺不会做，Shakti也无法选择任何一种禁奶茶。
沙克提能得到的投诉最少是多少?
输入
输入的第一行给出测试用例的数量，T T测试用例如下。每个测试用例以包含3个整数N、M和P的行开始，如上所述。然后，还有N多行，每一行都包含一个二进制字符串;这些代表了N个朋友的喜好。最后，还有M多行，每一行都包含一个二进制字符串;这些代表了奶茶商店不会生产的禁忌类型。二进制字符串仅由0和/或1个字符组成。
输出
对于每个测试用例，输出一行包含case #x: y，其中x是测试用例号(从1开始)，y是Shakti根据上面描述的规则能够得到的最小投诉数量。

在案例1中，有3个朋友，他们想要1100型，1010型和0000型的奶茶。如果Shakti可以选择类型1000，那么每个朋友会抱怨一次，总共3次。然而，类型1000在商店是不可用的。因此，在这些约束条件下，最优的解决方案是选择1100型。然后，他的朋友会分别投诉0次、2次和2次，总共投诉4次。
在示例案例#2中，Shakti的最佳选择是选择类型1110。每个朋友会抱怨一次，总共2次。注意，不同的朋友可能有相同的偏好。还要注意，无论大小数据集的限制都保证了至少有一种可能的奶茶类型是不被禁止的。
The milk tea in China is very delicious. There are many binary ("either-or") options for customizing a milk tea order, such as "with ice"/"no ice", "with sugar"/"no sugar", "with bubbles"/"no bubbles", "with pudding"/"no pudding", and so on. A customer's preferences for their milk tea can be represented as a binary string. For example, using the four properties above (in the order they are given), the string 1100 means "with ice, with sugar, no bubbles, no pudding".

Today, Shakti is on duty to buy each of his N friends a milk tea, at a shop that offers P binary options. But after collecting everyone's preferences, Shakti found that the order was getting too complicated, so Shakti has decided to buy the same type of milk tea for everyone. Shakti knows that for every friend, for every preference that is not satisfied, they will complain once. For example, if two of the friends have preferences for types 101 and 010, and Shakti chooses type 001, then the first friend will complain once and the second friend will complain twice, for a total of three complaints.

Moreover, there are M different forbidden types of milk tea that the shop will not make, and Shakti cannot choose any of those forbidden types.

What is the smallest number of complaints that Shakti can get?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line containing 3 integers N, M, and P, as described above. Then, there are N more lines, each of which contains a binary string; these represent the preferences of the N friends. Finally, there are M more lines, each of which contains a binary string; these represent the forbidden types of milk tea that the shop will not make. Binary strings consist only of 0 and/or 1 characters.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum number of complaints that Shakti can get, per the rules described above.

Limits
1 ≤ T ≤ 100.
All of the forbidden types of milk tea are different.
Small dataset
1 ≤ N ≤ 10.
1 ≤ M ≤ min(10, 2P - 1).
1 ≤ P ≤ 10.
Large dataset
1 ≤ N ≤ 100.
1 ≤ M ≤ min(100, 2P - 1).
1 ≤ P ≤ 100.
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
    //fclose(stdin);//关闭文件 
    //fclose(stdout);//关闭文件 
    return 0;
}