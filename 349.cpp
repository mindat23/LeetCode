#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//Solution 1:
/*
Description : Use set
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums2.begin(), nums2.end());
        set<int> res_set;

        for(int x : nums1){
            if(s.count(x)){
                res_set.insert(x);
            }
        }

        return vector<int>(res_set.begin(), res_set.end());
    }
};

//Solution 2: Two Points
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        vector<int> res;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else {
                if(res.empty() || res.back() != nums1[i]){
                    res.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return res;
    }
};