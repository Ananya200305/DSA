// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
        }
        
        vector<int>indegree(V, 0);
        
        for(int i = 0 ; i < V; i++){
            for(auto it : adj[i]){
                int v = it.first;
                indegree[v]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0 ; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]){
                int v = it.first;
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        
        for(int t : topo){
            if(dist[t] != INT_MAX){
                for(auto it : adj[t]){
                    int v = it.first;
                    int w = it.second;
                    if(dist[t] + w < dist[v]){
                        dist[v] = dist[t] + w;
                    }
                }
            }
        }
        
        for(int i = 0 ; i < V; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        
        return dist;
    }
};
