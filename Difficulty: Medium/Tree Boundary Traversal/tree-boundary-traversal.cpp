/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node* root){
        return root -> left == nullptr && root -> right == nullptr;
    }
    
    void addLeft(Node* root, vector<int>& res){
        Node* curr = root -> left;
        
        while(curr){
            if(!isLeaf(curr)){
                res.push_back(curr -> data);
            }
            
            if(curr -> left != nullptr){
                curr = curr -> left;
            }else{
                curr = curr -> right;
            }
        }
    }
    
    void addRight(Node* root, vector<int>& res){
        Node* curr = root -> right;
        
        vector<int> temp;
        
        while(curr){
            if(!isLeaf(curr)){
                temp.push_back(curr -> data);
            }
            
            if(curr -> right != nullptr){
                curr = curr -> right;
            }else{
                curr = curr -> left;
            }
        }
        
        for(int i = temp.size()-1 ; i >= 0; i--){
            res.push_back(temp[i]);
        }
    }
    
    void addLeaves(Node* root, vector<int>& res){
        if(isLeaf(root)){
            res.push_back(root -> data);
            return;
        }
        
        if(root -> left != nullptr){
            addLeaves(root -> left, res);
        }
        
        if(root -> right != nullptr){
            addLeaves(root -> right, res);
        }
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int>res;
        
        if(!isLeaf(root)){
            res.push_back(root -> data);
        }
        
        addLeft(root, res);
        addLeaves(root, res);
        addRight(root, res);
        
        return res;
    }
};