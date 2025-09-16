class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node){
        visited[node] = true;

        for(int neighbour = 0 ; neighbour < isConnected.size() ; neighbour++){
            if(isConnected[node][neighbour] == 1 && visited[neighbour] == false){
                dfs(isConnected, visited, neighbour);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n, false);
        int province = 0;

        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                province++;
                dfs(isConnected, visited, i);
            }
        }

        return province;
    }
};