#include<iostream>
#include<vector>
#include <algorithm>
#include<climits>
using namespace std;

//Solution 1
/*
Độ phức tạp lên đến O(nlogn)
-sort mảng 
-cho biến cnt chạy 2 lần từ 1->2
-Gán biến third là GTLN
-Kết thúc vòng lặp nếu cnt < 3 thì return nums[0];
-Nếu không thì return third lúc này third là thirdMax
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int third = nums[0];
        int i = 1;
        int cnt = 1;
        while(cnt < 3 && i < nums.size()){
           if (third != nums[i]) {
                third = nums[i];
                cnt++;
            }
            i++;
        }
        if(cnt < 3) return nums[0];
        return third;
    }
};



//Solution 2

/*
Cách này đòi tư duy hơn 1 xíu
khai báo các biến first,second,third là LLONG_MIN nhỏ nhất
dùng for each và xét điều kiện
- Nếu đã xét số đó ròi thì continue để bớt runtime
- Nếu num > first thì cập nhật third = second , second = first,first = num
-Nếu num > second thì update third = second , second = num
-Nếu num > third thì update third = num;
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;
        for(int num : nums){
            if(first == num || second == num || third == num) continue;
            if(num > first){
                third = second;
                second = first;
                first = num;
            } else if(num > second){
                third = second;
                second = num;
            }
            else if(num > third){
                third = num;
            }
        }
        return third == LLONG_MIN ? first : third;
    }
};