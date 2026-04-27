#include<iostream>
using namespace std;

//Use two points
class Solution {
public:

    bool isVowel(char c){
        c = tolower(c);
        if(c == 'a' || 
        c == 'e' || 
        c == 'i' || 
        c == 'o' || 
        c == 'u' ) return true;
        return false;
    }

    string reverseVowels(string s) {
        int l = 0;
        int r = s.length()-1;
        while(l<r){
            if(isVowel(s[l]) && isVowel(s[r])){
                swap(s[l],s[r]);
                l++;
                r--;
            }else if(!isVowel(s[r])){
                r--;
            }
            else if(!isVowel(s[l])){
                l++;
            }
            
        }
        return s;
    }
};