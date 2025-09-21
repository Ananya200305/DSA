class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int>adj[V];
        
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
        }
        
        queue<int>q;
        vector<int>indegree(V,0);
        
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i = 0 ; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int count = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        if(count == V) return false;
        return true;
    }
};