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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> stk;  // Stack to store nodes and their depth
        int i = 0, n = traversal.size();

        while (i < n) {
            int depth = 0;
            // Count the number of dashes (depth)
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }

            // Extract the node value
            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }

            // Create the node
            TreeNode* node = new TreeNode(value);

            // Find the correct parent in the stack
            while (!stk.empty() && stk.top().second >= depth) {
                stk.pop();
            }

            // Attach the node to its parent
            if (!stk.empty()) {
                if (!stk.top().first->left)
                    stk.top().first->left = node;
                else
                    stk.top().first->right = node;
            }

            // Push the new node onto the stack
            stk.push({node, depth});
        }

        // The root of the tree is the bottom-most node in the stack
        while (stk.size() > 1) stk.pop();
        return stk.top().first;
    }
};