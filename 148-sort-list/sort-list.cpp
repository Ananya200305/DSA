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
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast -> next != NULL){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return prev;
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode* head = NULL;

        if(l1 -> val < l2 -> val){
            head = l1;
            l1 = l1 -> next;
        }else{
            head = l2;
            l2 = l2 -> next;
        }

        ListNode* tail = head;

        while(l1 != NULL && l2 != NULL){
            if(l1 -> val < l2 -> val){
                tail -> next = l1;
                l1 = l1 -> next;
            }else{
                tail -> next = l2;
                l2 = l2 -> next;
            }
            tail = tail -> next;
        }

        if(l1 != NULL){
            tail -> next = l1;
        }else{
            tail -> next = l2;
        }

        return head;

    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode* mid = getMid(head);
        ListNode* rightHalf = mid -> next;
        mid -> next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHalf);

        return merge(left,right);
    }
};