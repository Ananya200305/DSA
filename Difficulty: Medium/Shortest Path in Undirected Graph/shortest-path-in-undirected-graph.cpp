class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        queue<pair<int, int>> q;
        q.push({src,0});
        
        vector<int> dist(adj.size(), -1);
        dist[src] = 0;
        
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            
            for(auto it : adj[node]){
                if(dist[it] == -1){
                    dist[it] = d+1;
                    q.push({it, d+1});
                }
            }
        }
        
        return dist;
    }
};