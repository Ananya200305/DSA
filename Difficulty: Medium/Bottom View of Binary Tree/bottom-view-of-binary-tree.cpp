/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        map<int, map<int, vector<int>>> map;
        queue<pair<Node*, pair<int, int>>>q;
        q.push({root, {0,0}});
        
        while(!q.empty()){
            Node* node = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            
            q.pop();
            
            map[x][y].push_back(node -> data);
            
            if(node -> left != nullptr){
                q.push({node -> left, {x - 1, y + 1}});
            }
            
            if(node -> right != nullptr){
                q.push({node -> right, {x + 1, y + 1}});
            }
        }
        
        vector<int>ans;
        
        for(auto p : map){
            auto f = p.second.rbegin();
            ans.push_back(f -> second.back());
        }
        
        return ans;
    }
};