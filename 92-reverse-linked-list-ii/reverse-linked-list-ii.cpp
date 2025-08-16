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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head -> next || left == right){
            return head;
        }

        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;

        int pos = 1;
        ListNode* temp = head;

        while(temp){
            if(pos == left-1){
                a = temp;
            }else if(pos == left){
                b = temp;
            }else if(pos == right){
                c = temp;
            }else if(pos == right+1){
                d = temp;
            }
            temp = temp -> next;
            pos++;
        }

        if(a){
            a -> next = NULL;
        }
        c -> next = NULL;

        ListNode* reversed = reverse(b);

        if(a){
            a -> next = reversed;
        }
        b -> next = d;

        return (a != NULL) ? head : reversed;
    }
};