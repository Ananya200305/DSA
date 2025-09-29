class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited){
        int row = grid.size();
        int col = grid[0].size();

        visited[i][j] = true;

        queue<pair<int, int>> q;
        q.push({i,j});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i = 0 ; i < 4; i++){
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == '1' && !visited[nr][nc]){
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int count = 0;

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for(int i = 0 ; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    count++;
                    bfs(grid, i, j, visited);
                }
            }
        }

        return count;
    }
};