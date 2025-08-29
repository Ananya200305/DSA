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
    ListNode* reverse(ListNode* start, ListNode* end){
        ListNode* prev = NULL;
        ListNode* curr = start;
        ListNode* next = NULL;

        while(curr != end){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;

        while(temp && count < k){
            temp = temp -> next;
            count++;
        }

        if(count < k) return head;

        ListNode* newHead = reverse(head, temp);

        head -> next = reverseKGroup(temp , k);

        return newHead;
    }
};