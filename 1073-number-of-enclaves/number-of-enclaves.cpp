class Solution {
public:
    void bfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited){
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>>q;
        q.push({i, j});
        visited[i][j] = 1;

        int x[] = {-1, 0, 1, 0};
        int y[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + x[i];
                int nc = c + y[i];

                if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 1 && visited[nr][nc] == 0){
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        int count = 0;

        for(int i = 0; i < col; i++){
            if(grid[0][i] == 1 && visited[0][i] == 0) bfs(grid, 0, i, visited);
            if(grid[row-1][i] == 1 && visited[row-1][i] == 0) bfs(grid, row-1, i, visited);
        }

        for(int i = 0; i < row; i++){
            if(grid[i][0] == 1 && visited[i][0] == 0) bfs(grid, i, 0, visited);
            if(grid[i][col-1] == 1 && visited[i][col-1] == 0) bfs(grid, i, col-1, visited);
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    count++;
                }
            }
        }

        return count;
    }
};