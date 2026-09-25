class Solution {
public:
    void bfs(vector<vector<bool>>& visited, int x, int y, vector<vector<char>>& grid){
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>>q;
        q.push({x,y});

        int i[] = {-1, 0, 1, 0};
        int j[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int z = 0; z < 4; z++){
                int nr = r + i[z];
                int nc = c + j[z];

                if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == '1' && visited[nr][nc] == false){
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        int count = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    count++;
                    bfs(visited, i, j, grid);
                }
            }
        }

        return count;
    }
};