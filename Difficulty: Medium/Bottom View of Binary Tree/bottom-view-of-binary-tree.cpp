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
    vector<int> bottomView(Node *root) {
        // map: x (hd) -> map: y (depth) -> vector of values (preserving insertion order)
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
            auto it = levelMap.rbegin(); // deepest y
            ans.push_back(it->second.back()); // last inserted value at deepest y
        }

        return ans;
    }
};
