// Pascal'Triangle
/*
Tạo 1 res với phần tử ban đầu là res = {{1}};
Mỗi lần lập tạo 1 vector số 1
sau đó lặp chạy từ 1 tới i
thay đổi các phần tử trong vector
sau đó push vào
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows;i++){
            vector<int> nums(i+1,1);
            for(int j = 1; j < i;j++){
                nums[j] = res[i-1][j-1] +  res[i-1][j];
            }
            res.push_back(nums);
        }
        
        return res;
    }
};


//Solution 2: Sử dụng toán học
/*
Mỗi phần tử trong tam giác Pascal là tổ hợp n chập k
với k là vị trí và n là độ dài vector
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows;i++){
            long long val = 1;
            vector<int> row;
            for(int j = 0; j <= i;j++){
                row.push_back(val);
                val = val*(i-j)/(j+1);
            }
            res.push_back(row);
        }
        
        return res;
    }
};
