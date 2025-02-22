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
    //     helper(node -> left,result);
    //     helper(node -> right,result);
    //     result.push_back(node -> val);
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> result;
        // helper(root, result);
        // return result;

        // vector<int> result;

        // if(root == NULL) {
        //     return result;
        // }

        // stack<TreeNode*> st1;
        // stack<TreeNode*> st2;

        // st1.push(root);
        // while(!st1.empty()){
        //     root = st1.top();
        //     st1.pop();
        //     st2.push(root);
        //     if(root -> left != NULL){
        //         st1.push(root -> left);
        //     }
        //     if(root -> right != NULL){
        //         st1.push(root -> right);
        //     }
        // }
        // while(!st2.empty()){
        //     result.push_back(st2.top() -> val);
        //     st2.pop();
        // }
        // return result;

        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;
        // st.push(current);
        while(current != NULL || !st.empty()){
            if(current != NULL){
                st.push(current);
                current = current -> left;
            }else{
                TreeNode* temp = st.top() -> right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    result.push_back(temp -> val);
                    while(!st.empty() && temp == st.top() -> right){
                        temp = st.top();
                        st.pop();
                        result.push_back(temp -> val);
                    }
                }else{
                    current = temp;
                }
            }
        }
        return result;
    }
};