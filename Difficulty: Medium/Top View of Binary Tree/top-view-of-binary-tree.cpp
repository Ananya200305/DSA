/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        map<int, map<int, vector<int>>> mp;
        queue<pair<Node*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            mp[x][y].push_back(node->data);  // maintain insertion order

            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<int> ans;
        for (auto& [x, levelMap] : mp) {
            auto it = levelMap.begin(); 
            ans.push_back(it->second.front()); 
        }

        return ans;
    }
};