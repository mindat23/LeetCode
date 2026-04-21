#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
Description:
Kĩ thuật ronate hay sử dụng k = k % độ dài
Sử dụng kĩ thuật nối vòng (nối nốt cuối cùng lên đầu)
Sau đó cắt khúc len - k
Cho head nằm ở khúc đó
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int len = 1;
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
            len++;
        }
        k %= len;
        if(k == 0) return head;
        tail->next = head;
        ListNode* newTail = head;
        int cnt = 1;
        while(cnt < len - k){
            newTail = newTail->next;
            cnt++;
        }
        head = newTail->next;
        newTail->next = NULL;
        return head;
    }
};
