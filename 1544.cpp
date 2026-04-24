#include<iostream>
#include<stack>
using namespace std;

// Using stack


class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (int i = 0 ; i < s.length();i++){
            if(
                !st.empty() &&
                st.top() != s[i] &&
                tolower(st.top()) == tolower(s[i])
            ){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        string res = "";

        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};