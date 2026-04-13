// Move Zeroes

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
      for(int i = 0;i < nums.size();i++){
        if(nums[i] != 0){
            nums[k++] = nums[i];
        }
        else if(nums[i] == 0) continue;
      }

      for(int i = k; i < nums.size();i++){
        nums[i] = 0;
      }
    }
};

