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
        if(head == NULL) return nullptr;

        ListNode* temp = head;
        int size = 1;

        while(temp && temp -> next){
            size++;
            temp = temp -> next;
        }

        if(size == 1 || n > size) return NULL;

        temp = head;
        if(n == size){
            head = head -> next;
            temp -> next = NULL;
            delete temp;
            return head;
        }

        for(int i = 0; i < size - n - 1; i++){
            temp = temp -> next;
        }

        ListNode* toDel = temp -> next;
        temp -> next = temp -> next -> next;
        delete toDel;
        return head;
    }
};