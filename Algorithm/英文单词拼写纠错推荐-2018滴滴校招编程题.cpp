#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
/*
英文单词拼写纠错推荐
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
英文单词拼写的时候可能会出现拼写错误的情况(typo)。下面的题目，我们尝试实现拼写纠错推荐的功能。

字串编辑距离是衡量字串间相似度的常见手段。

①字串编辑距离：是指利用字符操作，把字符串A转换成字符串B所需要的最少操作数。

②字串操作包括：删除字符(removal)、插入字符(insertion)、修改字符(substitution)。

③使用以下规则对推荐纠错选项进行相似度排序。得分越高，认为相似度越低

只涉及到26个英文字符、不区分大小写。

删除(removal)  3分

插入(insertion) 3分

修改(substitution) ：

(q w e r t a s d f g z x c v ) （y u i o p h j k l b n m）

以上两个分组内的字符修改1分，两个分组间字符修改 2分。

输入
·每行一个输入。空格分割参数。 ·第一个参数是目标单词(可能存在typo) ·后面若干空格分割参数(个数不定)是字典单词，作为候选纠错项(也可能和第一个参数重复)。

输出
·按照上面的纠错规则字串相似度最小编辑距离进行排序，给出3个(如有)对应的纠错候选。 ·如得分相同，则按照输入顺序进行排序。


样例输入
slep slap sleep step shoe shop snap slep
样例输出
slep slap step
*/

string source;
unordered_map<string, int> mp;
int ldistance(const string source, const string target)
{
    //step 1
    string lefthand = "qwertasdfgzxcv";
    string righthand = "yuiophjklbnm";

    int n = source.length();
    int m = target.length();
    if (m == 0) return n;
    if (n == 0) return m;
    //Construct a matrix
    typedef vector< vector<int> >  Tmatrix;
    Tmatrix matrix(n + 1);
    for (int i = 0; i <= n; i++)  matrix[i].resize(m + 1);

    //step 2 Initialize

    for (int i = 1; i <= n; i++) matrix[i][0] = i;
    for (int i = 1; i <= m; i++) matrix[0][i] = i;

    //step 3
    for (int i = 1; i <= n; i++)
    {
        const char si = source[i - 1];
        //step 4
        for (int j = 1; j <= m; j++)
        {

            const char dj = target[j - 1];
            //step 5
            int cost;
            if (si == dj) {
                cost = 0;
            }
            else {
                if((lefthand.find(si)!= lefthand.npos && righthand.find(dj)!=righthand.npos) || (lefthand.find(dj) != lefthand.npos && righthand.find(si) != righthand.npos))
                cost = 2;
                else cost = 1;


            }
            //step 6
            const int above = matrix[i - 1][j] + 1;
            const int left = matrix[i][j - 1] + 1;
            const int diag = matrix[i - 1][j - 1] + cost;
            matrix[i][j] = min(above, min(left, diag));

        }
    }//step7
    return matrix[n][m]+2*abs(n-m);
}
bool judge(string a,string b) {
    if (ldistance(source, a) == ldistance(source, b)) return mp[a] < mp[b];
    return  ldistance(source, a) < ldistance(source, b);
}
void solve() {
    string in;
    cin >> in;
    source = in;
    string tar;
    vector<string> target;
    int number = 0;
    while (cin >> tar) {
        target.push_back(tar);
        if(mp.find(tar)==mp.end()) mp[tar] = number;
        number++;
    }
    //for (auto i : target) cout << i << endl;
    sort(target.begin(), target.end(), judge);
    if (target.size() >= 3){
        for (int i = 0; i < 3; i++) {
            if (i == 2) cout << target[i] << endl;
            else cout << target[i] << " ";
        }
    }
    else {
        for (int i = 0; i < target.size(); i++) {
            if (i == target.size()-1) cout << target[i] << endl;
            else cout << target[i] << " ";
        }
    }
        
}
int main() {
   // freopen("in.txt", "r", stdin);
    solve();
    return 0;
}