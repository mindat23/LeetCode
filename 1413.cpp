#include<iostream>
#include<vector>
using namespace std;


//BestSolution:Tìm min của nó rồi lấy 1-min là ra
/*
Description: Mình tìm minprefix sau đó lấy 1 - minprefix là xong
*/
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int minPrefix = 0;

        for (int num : nums) {
            sum += num;
            minPrefix = min(minPrefix, sum);
        }

        return 1 - minPrefix;
    }
};


/*
Bad solution : BruteForce O(n^2)
 */
class Solution {
public:
    int minStartValue(vector<int>& nums) {
       int cnt = 1;
       while(true){
            int startVal = cnt;
            for(int i = 0; i <nums.size();i++){
                startVal += nums[i];
                if(startVal < 1) break;
                else continue;
            }
            if(startVal >= 1) return cnt;
            cnt++;
       } 
    }
};