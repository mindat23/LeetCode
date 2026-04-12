#include<iostream>
#include<vector>
using namespace std;


//Solution 1: O(n^2)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 1; i <= nums.size();i++){
            int found = 0;
            for(int j = 0 ; j < nums.size();j++){
                if(nums[j] == i ){
                    found = 1;
                }
            }
            if(found == 0){
                res.push_back(i);
            }
        }
        return res;
    }
};


//Solution 2: O(n)
/*
Description :
-Mức độ : Medium
-Hint : Đánh dấu các index đã xuất hiện thay giá trị tại index đó bằng số âm
nếu là số dương thì index + 1 chưa xuất hiện
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0;i < nums.size();i++){
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0){
                nums[index] = - nums[index];
            }
        }

        for(int i = 0; i < nums.size();i++){
            if(nums[i] > 0){
                res.push_back(i+1);
            }
        }
        return res;
    }
};