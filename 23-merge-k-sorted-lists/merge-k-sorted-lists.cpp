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
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1 -> val < l2 -> val){
            l1 -> next = merge(l1 -> next, l2);
            return l1;
        }else{
            l2 -> next = merge(l1, l2 -> next);
            return l2;
        }
    }
    ListNode* divideAndConquer(vector<ListNode*>& lists, int left, int right){
        if(left == right) return lists[left];

        int mid = left + (right - left)/2;

        ListNode* l1 = divideAndConquer(lists, left, mid);
        ListNode* l2 = divideAndConquer(lists, mid+1, right);

        return merge(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return divideAndConquer(lists, 0, lists.size()-1);
    }
};