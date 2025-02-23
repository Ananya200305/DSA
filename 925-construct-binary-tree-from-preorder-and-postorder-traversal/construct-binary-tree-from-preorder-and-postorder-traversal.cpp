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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);

        int preI = 1;
        int postI = 0;

        while(!st.empty()){
            TreeNode* current = st.top();
            if(current -> val == postorder[postI]){
                st.pop();
                postI++;
            }else{
                TreeNode* newNode = new TreeNode(preorder[preI++]);
                if(current -> left == NULL){
                    current -> left = newNode;
                }else{
                    current -> right = newNode;
                }
                st.push(newNode);
            }
        }
        return root;
    }
};