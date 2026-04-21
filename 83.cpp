// Remove Duplicate Sorted List
#include<iostream>
using namespace std;



  
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 


class Solution {
    public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* cur = head;
        ListNode* tmp = cur->next;
        while(cur && tmp){
            if(cur->val == tmp->val){
                cur->next = tmp->next;
                ListNode* temp = tmp;
                tmp = tmp->next;
                delete temp;
            } else if(cur->val != tmp->val){
                cur = tmp;
                tmp = tmp->next;
            }
        }
        return head;
    }
};