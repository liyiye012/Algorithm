#include<iostream>
using namespace std;
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}
void SelectionSort(int *num, int len) {
    for (int i = 0; i < len; i++) { ¡¢¡¢
        int index = i;
        for (int j = i+1; j < len; j++) {
            if (num[j] < num[index]) index = j;
        }
        if (index != i) swap(&num [i], &num [index]);
    }
}
void main() {
    int num[5] = {56,12,80,91,20};
    SelectionSort(num, 5);
    for (int i = 0; i < 5; i++) cout << num[i] << "  ";
}