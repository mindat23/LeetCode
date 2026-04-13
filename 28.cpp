#include<iostream>
using namespace std;
//Solution 1 : Kĩ thuật bình thường
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() < needle.length()) return -1;
        int i = 0;
        while (i <= haystack.length() - needle.length()){
            if(haystack[i] == needle[0]){
                string s = "";
                for(int j = i ; j < i + needle.length();j++){
                    s += haystack[j];
                }
                if(s == needle) return i;
            }
            i++;
        }
        return -1;
    }
};

//Solution 2: Two points tối ưu memory hơn
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() < needle.length()) return -1;
        for(int i = 0; i <= haystack.length()-needle.length();i++){
            int j = 0;
            while(j < needle.length() && haystack[i+j] == needle[j]){
                j++;
            }
            if(j == needle.length()) return i;
        }
        return -1;
    }
};


