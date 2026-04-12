// Add two num
/*
Description:
Ex :
l1 = 2->4->3 => val = 342
l2 = 5->6->4 => val = 465
-Nếu l1 != NULL thì lấy l1->val , nếu bằng null lấy số 0
-Tương tự với l2
và 1 biến nhớ
-Sử dụng cách cộng của lớp 1 
lấy biến nhớ là carry = total / 10;
lấy giá trị để nối là node = total %10
sau đó nối vô dummy
*Lặp tới khi nào (l1  và l2) = null và carry = 0
*/
#include<iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        int carry = 0;
        while(l1 || l2 || carry != 0){
            int val1 = (l1 != NULL) ? l1->val :0;
            int val2 = (l2 != NULL) ? l2->val :0;

            int total = val1+val2+carry;
            carry = total/10;
            int node = total%10;
            cur->next = new ListNode(node);
            cur = cur->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dummy.next;
    }
};