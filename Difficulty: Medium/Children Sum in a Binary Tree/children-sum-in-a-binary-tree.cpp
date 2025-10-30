/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool isSumProperty(Node *root) {
        if(root == nullptr) return true;
        if(root -> left == nullptr && root -> right == nullptr) return true;
        
        int left = root -> left ? root -> left -> data : 0;
        int right = root -> right ? root -> right -> data : 0;
        
        if(root -> data == left + right && isSumProperty(root -> left) && isSumProperty(root -> right)){
            return true;
        }
        
        return false;
    }
};