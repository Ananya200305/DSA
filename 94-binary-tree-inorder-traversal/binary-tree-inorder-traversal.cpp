/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // void helper(TreeNode* node, vector<int>& result){
    //     if(!node) return;
    //     helper(node -> left, result);
    //     result.push_back(node -> val);
    //     helper(node -> right, result);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> result;
        // helper(root, result);
        // return result;

        vector <int> result;

        if(root == NULL) return result;

        TreeNode* node = root;

        stack<TreeNode*> st;

        while(true){
            if(node != NULL){
                st.push(node);
                node = node -> left;
            }else{
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                result.push_back(node -> val);
                node = node -> right;
            }
        }

        return result;
    }
};