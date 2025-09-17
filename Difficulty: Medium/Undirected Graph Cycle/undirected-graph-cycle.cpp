class Solution {
  public:
    bool bfs(int start, vector<int> adj[], vector<int>& visited){
        queue<pair<int, int>>q;
        visited[start] = 1;
        q.push({start, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(auto neigh : adj[node]){
                if(!visited[neigh]){
                    visited[neigh] = 1;
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
        
        vector<int>visited(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(bfs(i, adj, visited)) return true; 
            }
        }
        
        return false;
    }
};