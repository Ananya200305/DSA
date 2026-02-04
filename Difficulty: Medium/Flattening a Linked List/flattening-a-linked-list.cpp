/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* convert(vector<int>& ans){
        if(ans.size() == 0) return NULL;
        
        Node* head = new Node(ans[0]);
        Node* temp = head;
        
        for(int i = 1; i < ans.size(); i++){
            Node* newNode = new Node(ans[i]);
            temp -> bottom = newNode;
            temp = newNode;
        }
        
        return head;
    }
    Node *flatten(Node *root) {
        vector<int>ans;
        Node* temp = root;
        
        while(temp){
            Node* temp2 = temp;
            while(temp2){
                ans.push_back(temp2 -> data);
                temp2 = temp2 -> bottom;
            }
            temp = temp -> next;
        }
        
        sort(ans.begin(), ans.end());
        
        Node* newHead = convert(ans);
        
        return newHead;
    }
};