class Solution {
  public:
    bool bfs(vector<int>adj[], vector<bool>& visited, int n){
        queue<pair<int, int>> q;
        q.push({n, -1});
        
        visited[n] = true;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(auto neigh : adj[node]){
                if(!visited[neigh]){
                    visited[neigh] = true;
                    q.push({neigh, node});
                }else if(neigh != parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>visited(V, false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(bfs(adj, visited, i)){
                    return true;
                }
            }
        }
        
        return false;
    }
};