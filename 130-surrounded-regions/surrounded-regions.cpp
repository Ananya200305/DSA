class Solution {
public:
    void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j){
        int row = board.size();
        int col = board[0].size();

        queue<pair<int, int>>q;
        q.push({i,j});
        visited[i][j] = true;

        int x[] = {-1, 0, 1, 0};
        int y[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + x[i];
                int nc = c + y[i];

                if(nr >= 0 && nr < row 
                && nc >= 0 && nc < col
                && board[nr][nc] == 'O'
                && !visited[nr][nc]){
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<bool>>visited(row, vector<bool>(col, false));

        for(int i = 0; i < col; i++){
            if(board[0][i] == 'O' && !visited[0][i]) bfs(board, visited, 0, i);
            if(board[row-1][i] == 'O' && !visited[row-1][i]) bfs(board, visited, row-1, i);
        }

        for(int i = 0; i < row; i++){
            if(board[i][0] == 'O' && !visited[i][0]) bfs(board, visited, i, 0);
            if(board[i][col-1] == 'O' && !visited[i][col-1]) bfs(board, visited, i, col-1);
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};