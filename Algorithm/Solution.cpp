#include<vector>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
struct Point {
    int x;
    int y;
}p1, p2, p3, p4;
class Solution {
public:
    void output(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }


};
int main() {
    Solution solution;
    int n[] = { 6, 7, 5, 9, 8 };
    vector<int> nums(n, n + 5); //将数组n的前5个元素作为向量a的初值
                                //solution.output(nums);
                                //vector<int> nums(&n[1], &n[4]);//将n[1] - n[4]范围内的元素作为向量a的初值 ????
                                //solution.output(nums);
                                /*  p1 = { 0,3 };
                                p2 = { 1,1 };
                                p3 = { 3,4 };
                                p4 = { 5,6 };
                                vector<Point> p;
                                p.push_back(p1);
                                p.push_back(p2);
                                p.push_back(p3);
                                p.push_back(p4);*/
  
    return 0;
}