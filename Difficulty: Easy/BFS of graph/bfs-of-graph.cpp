class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int>bfs;
        vector<bool> visited(adj.size(), false);
        queue<int>q;
        
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(int neighbour : adj[node]){
                if(visited[neighbour] == false){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        
        return bfs;
    }
};