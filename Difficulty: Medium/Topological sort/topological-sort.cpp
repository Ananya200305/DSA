class Solution {
  public:
    void dfs(int node, vector<int>adj[], vector<int> & visited, stack<int>& st){
        visited[node] = 1;
        
        for(auto it : adj[node]){
            if(visited[it] == false){
                dfs(it, adj, visited, st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int>visited(V, 0);
        stack<int>st;
        
        for(int i = 0 ; i < V; i++){
            if(visited[i] == 0) dfs(i, adj, visited, st);
        }
        
        vector<int> res;
        
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
    }
};