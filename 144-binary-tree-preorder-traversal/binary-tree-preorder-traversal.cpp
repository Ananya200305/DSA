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
    //     result.push_back(node->val);
    //     helper(node -> left, result);
    //     helper(node -> right, result);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> result;
        // helper(root,result);
        // return result;

        vector<int> result;

        if(root == NULL) return result;

        stack<TreeNode*> st;

        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            result.push_back(root -> val);
            if(root -> right != NULL){
                st.push(root -> right);
            }
            if(root -> left != NULL){
                st.push(root -> left);
            }
        }


        return result;
    }
};