#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Three sum:
/*
-Sort nums
-Two point
-If nums[i] is exist continue for loop
-if nums[l] is exist l++
-if nums[r] is exist r--
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-2;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1;
            int r = nums.size()-1;
            while(l < r){
                int threesum = nums[i] + nums[l] + nums[r];
                if(threesum == 0){
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l-1]){
                        l++;
                    }
                    while(l < r && nums[r] == nums[r+1]){
                        r--;
                    }
                } else if(threesum < 0){
                    l++;
                } else if(threesum > 0){
                    r--;
                }
            }
        }
        
        return res;
    }
};