/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL || k == 0) return head;

        int size = 0;
        ListNode* temp = head;
        ListNode* tail = NULL;

        while(temp){
            size++;
            tail = temp;
            temp = temp -> next;
        }

        k = k % size;
        if(k == 0) return head;

        int last = size - k;
        temp = head;

        for(int i = 1 ; i < last; i++){
            temp = temp -> next;
        }

        ListNode* newHead = temp -> next;
        temp -> next = NULL;
        tail -> next = head;

        return newHead;
    }
};