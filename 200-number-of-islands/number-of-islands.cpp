class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
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
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
                && grid[nRow][nCol] == '1' && !visited[nRow][nCol]){
                    visited[nRow][nCol] = true;
                    q.push({nRow, nCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0; 
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col,0));
        int count = 0;

        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < col; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    count++;
                    bfs(grid, visited, i, j);
                }
            }
        }

        return count;
    }
};
