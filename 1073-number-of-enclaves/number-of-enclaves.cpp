class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j){
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>>q;
        q.push({i, j});
        visited[i][j] = 1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int nr = r + delRow[k];
                int nc = c + delCol[k];

                if(nr >= 0 && nr < row
                && nc >= 0 && nc < col
                && grid[nr][nc] == 1
                && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        for(int i = 0 ; i < col; i++){
            if(grid[0][i] == 1 && !visited[0][i]) bfs(grid, visited, 0, i);
            if(grid[row-1][i] == 1 && !visited[row-1][i]) bfs(grid, visited, row-1, i);
        }

        for(int j = 0 ; j < row; j++){
            if(grid[j][0] == 1 && !visited[j][0]) bfs(grid, visited, j, 0);
            if(grid[j][col-1] == 1 && !visited[j][col-1]) bfs(grid, visited, j, col-1);
        }

        int count = 0;

        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < col; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    count++;
                }
            }
        }

        return count;
    }
};