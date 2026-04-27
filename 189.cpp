#include<iostream>
#include<vector>
using namespace std;

//Solution 1: Twopoints combine with reverse
class Solution {
public:
    void reverse(vector<int>& a,int l,int r){
        while(l<r){
            swap(a[l],a[r]);
            l++;
            r--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(k == 0) return;
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
};

//Solution 2: Bruteforce
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for(int i = 0; i < k;i++){
            int temp = nums[nums.size()-1];
            for(int j = nums.size()-1; j >0;j--){
                nums[j] = nums[j-1];
            }
            nums[0] = temp;
        }
    }
};