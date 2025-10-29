class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, queue<pair<pair<int, int>, int>>& q, int freshCount){
        int row = grid.size();
        int col = grid[0].size();

        int x[] = {-1, 0, 1, 0};
        int y[] = {0, 1, 0, -1};

        int min = 0;
        int count = 0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int m = q.front().second;

            min = max(m, min);

            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + x[i];
                int nc = c + y[i];

                if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 1 && visited[nr][nc] != 2){
                    visited[nr][nc] = 2;
                    q.push({{nr,nc}, m+1});
                    count++;
                }
            }
        }
        return (freshCount == count) ? min : -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col,0));
        queue<pair<pair<int, int>, int>> q;

        int freshCount = 0;

        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        return bfs(grid, visited, q, freshCount);
    }
};