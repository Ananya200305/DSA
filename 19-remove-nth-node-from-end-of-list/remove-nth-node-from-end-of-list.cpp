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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;

        while(temp){
            size++;
            temp = temp -> next;
        }

        if(size == 1 || n > size) return NULL;

        n = size - n;
        temp = head;
        if(n == 0){
            head = head -> next;
            temp -> next = NULL;
            delete temp;
            return head;
        }

        for(int i = 1; i < n; i++){
            temp = temp -> next;
        }

        ListNode* toDel = temp -> next;
        temp -> next = temp -> next -> next;
        delete toDel;
        return head;
    }
};