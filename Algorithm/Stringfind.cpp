#include<iostream>
#include<string>
using namespace std;
//���Ŵ����ݱ���2018 ʵ��Ѱ��ƥ�����ַ�����λ��
int stringfind(string source, string target) {
    int len1 = source.size();
    int len2 = target.size();
    int index = -1;
    for (int i = 0; i < len1; i++) {
        if (source[i] != target[0]) continue;
        int j = 0;
        while (j != len2 && i + j < len1) {
            j++;
            if (source[i + j] != target[j]) break;
        }
        if (j == len2) return i;
    }
    return index;
}
void main() {
    string source;
    string target;
    cin >> source;
    cin >> target;
    cout << stringfind(source, target);
}