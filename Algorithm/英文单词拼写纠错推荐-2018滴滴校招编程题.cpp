#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
/*
Ӣ�ĵ���ƴд�����Ƽ�
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
Ӣ�ĵ���ƴд��ʱ����ܻ����ƴд��������(typo)���������Ŀ�����ǳ���ʵ��ƴд�����Ƽ��Ĺ��ܡ�

�ִ��༭�����Ǻ����ִ������ƶȵĳ����ֶΡ�

���ִ��༭���룺��ָ�����ַ����������ַ���Aת�����ַ���B����Ҫ�����ٲ�������

���ִ�����������ɾ���ַ�(removal)�������ַ�(insertion)���޸��ַ�(substitution)��

��ʹ�����¹�����Ƽ�����ѡ��������ƶ����򡣵÷�Խ�ߣ���Ϊ���ƶ�Խ��

ֻ�漰��26��Ӣ���ַ��������ִ�Сд��

ɾ��(removal)  3��

����(insertion) 3��

�޸�(substitution) ��

(q w e r t a s d f g z x c v ) ��y u i o p h j k l b n m��

�������������ڵ��ַ��޸�1�֣�����������ַ��޸� 2�֡�

����
��ÿ��һ�����롣�ո�ָ������ ����һ��������Ŀ�굥��(���ܴ���typo) ���������ɿո�ָ����(��������)���ֵ䵥�ʣ���Ϊ��ѡ������(Ҳ���ܺ͵�һ�������ظ�)��

���
����������ľ�������ִ����ƶ���С�༭����������򣬸���3��(����)��Ӧ�ľ����ѡ�� ����÷���ͬ����������˳���������


��������
slep slap sleep step shoe shop snap slep
�������
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