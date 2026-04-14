#include<iostream>
#include<vector>
using namespace std;
//Pascal triangle 2

// Sử dụng công thức toán học
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> nums;
        long long val = 1;
        for(int i = 0; i <= rowIndex;i++){
            nums.push_back(val);
            val = val * (rowIndex - i)/(i+1);
        }
        return nums;
    }
};