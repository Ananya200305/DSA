class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node){
        visited[node] = true;

        for(int n = 0 ; n < isConnected.size(); n++){
            if(isConnected[node][n] == 1 && visited[n] == false){
                dfs(isConnected, visited, n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);

        int province = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < n; j++){
                if(visited[i] == false){
                    province++;
                    dfs(isConnected, visited, i);
                }
            }
        }

        return province;
    }
};