#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
���ӣ�https://www.nowcoder.com/questionTerminal/69606208a7734ae0895724cfb951aef8?toCommentId=1862515
��Դ��ţ����

ţţ��һЩ�ų�һ�е������Ρ�ÿ���������Ѿ���Ⱦ�ɺ�ɫ������ɫ��ţţ���ڿ���ѡ������һ��������Ȼ������������ɫ������һ�ֽ���Ⱦɫ,��������ε���ɫ���ᱻ���ǡ�ţţ��Ŀ���������Ⱦɫ֮��,ÿ����ɫR����ÿ����ɫG������������ţţ��֪����������ҪͿȾ���������Ρ�
��������ʾ: s = RGRGR
����ͿȾ֮����RRRGG����Ҫ����,ͿȾ�ĸ���Ϊ2,û�б�������õ�ͿȾ������
��������:
�������һ���ַ���s,�ַ���s����length(1 �� length �� 50),����ֻ����'R'����'G',�ֱ��ʾ��ɫ����ɫ��


�������:
���һ������,��ʾţţ������ҪͿȾ������������
ʾ��1
����
RGRGR
���
2
*/
int main()
{
    string str = "";
    getline(cin, str);
    int size = str.size();
    vector<int>ldp(size, 0);
    vector<int>rdp(size, 0);
    // ��д��ǰldp�е�ǰ����ߵ�G�ĸ���
    int l = 0;
    for (int i = 0; i<size; ++i)
    {
        ldp[i] = l;
        if (str[i] == 'G')
            ++l;
    }
    // ��д��ǰrdp�е�ǰ���ұߵ�R�ĸ���
    int r = 0;
    for (int i = size - 1; i >= 0; --i)
    {
        rdp[i] = r;
        if (str[i] == 'R')
            ++r;
    }
    // ��ʼ����
    int res = 100;
    for (int i = 0; i<size; ++i)
    {
        if (ldp[i] + rdp[i] < res)
            res = ldp[i] + rdp[i];
    }
    cout << res << endl;
    return 0;
}