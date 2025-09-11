class Solution {
public:
    void dfsHelper(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& res) {
        visited[node] = true;
        res.push_back(node);

        // Explore neighbors in natural order (left to right)
        for (int v : adj[node]) {
            if (!visited[v]) {
                dfsHelper(v, adj, visited, res);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> res;
        vector<bool> visited(n, false);

        // handle disconnected graphs
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfsHelper(i, adj, visited, res);
            }
        }

        return res;
    }
};
