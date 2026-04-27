#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//Solution 1 : BruteForce
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cur = headB;
        while(cur){
            ListNode* tmp = headA;
            while(tmp){
                if(tmp == cur) return tmp;
                tmp = tmp->next;
            }
            cur = cur->next;
        }
        return NULL;
    }
};

//Solution 2:Two points
/*
Description:len(A+B) = len(B+A)
Cho trỏ chạy từ list A sang list B
Con trỏ còn lại chạy từ list B sang list A
Khi đó chúng sẽ gặp nhau tại điểm đó
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while(a!=b){
            a = (a == NULL) ? headB:a->next;
            b = (b == NULL) ? headA:b->next;
        }
        return a;
    }
};