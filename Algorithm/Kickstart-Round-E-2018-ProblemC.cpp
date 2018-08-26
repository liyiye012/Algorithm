#include <iostream>
#include<unordered_map>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
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
    s.erase(it, it1);//左闭右开，删除的是it指向的元素
}
/* 问题巴胡正和巴拉玩棋盘游戏。每个玩家有3 * N张不同力量值的军队卡。游戏中有三个战场。每个玩家必须正面朝下在战场上分发他们的纸牌，这样每个战场就能得到他们的N张纸牌。当游戏开始时，所有的牌都会显示出来。对于每个战场，每个玩家都要计算出他们的N张牌在战场上的力量值，然后玩家比较这些值。如果一个玩家拥有更高的总数，这个玩家就会赢得这个战场。如果总数相同，巴拉就赢得了战场;这是他的特殊优势。游戏的整体赢家是那些赢得最多战场的玩家。(既然有3个战场，可以保证不会出现全面的平局。)巴拉认为他的优势足以使他获胜，所以他只是随机洗牌，把第一个N放在第一个战场上，第二个N放在第二个战场上，最后一个N放在第三个战场上。即使巴胡处于劣势，他仍然会努力争取胜利!找到他赢的概率如果他把牌分配得最好。请注意，所有的巴拉牌都是正面朝下的，所以巴胡必须在看到巴拉牌的分配前选择他的牌的分配。输入输入的第一行给出测试用例的数量，T T测试用例如下;每一行由三行组成。第一行包含整数N，如上所述。第二行包含3 * N个整数A0 A1…， A3*N-1，表示八户牌的强度值。第三行包含3 * N个整数B0 B1…， B3*N-1，表示巴拉卡的强度值。输出对于每个测试用例，输出一行包含case #x: y，其中x是测试用例号(从1开始)，y是上面描述的概率。如果y在正确答案的10-6的绝对或相对误差范围内，则认为它是正确的。请参阅FAQ以了解这意味着什么，以及我们接受的实数格式。限制1≤T≤100。1≤Ai≤106,我。1≤Bi≤106,我。小数据集N = 3。大型数据集3≤N≤5。样本输入 输出 232 2 2 2 2 2 3 32 2 2 2 2 2 2 2 2 2 2 2 232 2 2 2 2 2 3 32 2 2 2 2 2 2 2 3例# 1:1.000000000例# 2:0.333333333在案例1中，八虎可以将牌(2,2,2)放在第一个战场上，(2,2,3)放在第二个战场上，(2,2,3)放在第三个战场上。因为巴拉的牌都是2张，所以巴拉赢了第一个战场，巴虎赢了第二个和第三个战场。
Problem
Bahu is playing a board game with Bala. Each player has 3 * N army cards with various strength values. There are 3 battlefields in the game. Each player must distribute their cards among the battlefields, face down, such that each battlefield gets exactly N of their cards.

When the game begins, all cards will be revealed. For each battlefield, each player sums up the strength values of their N cards in that battlefield, and then the players compare those totals. If one player has a higher total, that player wins that battlefield. If the totals are the same, Bala wins that battlefield; this is his special advantage.

The overall winner of the game is the player who wins the most battlefields. (Since there are 3 battlefields, it is guaranteed that there will not be an overall tie.)

Bala thinks that his advantage is enough to make him win, so he just randomly shuffles his cards and puts the first N on the first battlefield, the next N on the second battlefield, and the last N on the third battlefield.

Even though Bahu is at a disadvantage, he is still going to try to win! Find the probability that he will win if he distributes his cards optimally. Note that all Bala's cards are faced down so Bahu must choose the distribution of his cards before seeing the distribution of Bala's cards.

Input
The first line of the input gives the number of test cases, T. T test cases follow; each consists of three lines. The first line contains an integer N, as described above. The second line contains 3 * N integers A0, A1, ... , A3*N-1, representing the strength values of Bahu's cards. The third line consists of 3 * N integers B0, B1, ... , B3*N-1, representing the strength values of Bala's cards.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the probability described above. y will be considered correct if it is within an absolute or relative error of 10-6 of the correct answer. See the FAQ for an explanation of what that means, and what formats of real numbers we accept.

Limits
1 ≤ T ≤ 100.
1 ≤ Ai ≤ 106, for all i.
1 ≤ Bi ≤ 106, for all i.
Small dataset
N = 3.
Large dataset
3 ≤ N ≤ 5.
Sample

Input 
 	
Output 
 
2
3
2 2 2 2 2 2 2 3 3
2 2 2 2 2 2 2 2 2
3
2 2 2 2 2 2 2 3 3
2 2 2 2 2 2 2 2 3

Case #1: 1.000000000
Case #2: 0.333333333

In Sample Case #1, Bahu can put cards (2, 2, 2) in first battle field, (2, 2, 3) in second battle field and (2, 2, 3) in third battle field. As all Bala's cards are 2, Bala wins the first battle field and Bahu wins the second and third battle field.*/
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