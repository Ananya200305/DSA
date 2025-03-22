class Solution {
public:
    void bfs(int i, unordered_map<int, vector<int>>& adj, vector<bool>& visited, int &vertex, int &edge){
        queue<int> que;
        que.push(i);
        visited[i] = true;

        while(!que.empty()){
            int curr = que.front();
            que.pop();
            vertex++;
            edge = edge + adj[curr].size();

            for(auto &next : adj[curr]){
                if(visited[next] == false){
                    visited[next] = true;
                    que.push(next);
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int result = 0;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        } 

        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++){
            if(visited[i] == true){
                continue;
            }

            int vertex = 0;
            int edge = 0;

            bfs(i,adj,visited,vertex,edge);

            if(vertex*(vertex-1)/2 == edge/2){
                result++;
            }
        }

        return result;
    }
};