class Solution {
public:
    vector<vector<string>>res;
    bool isSafe(vector<string> & board, int row, int col){
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q') return false;
        }

        for(int i = 1; i <= min(row, col); i++){
            if(board[row-i][col-i] == 'Q') return false;
        }

        for(int i = 1; i <= min(row, (int)board.size()-1-col); i++){
            if(board[row-i][col+i] == 'Q') return false;
        }

        return true;
    }
    void helper(vector<string> & board, int row){
        if(row == board.size()){
            res.push_back(board);
            return;
        }

        for(int col = 0 ; col < board.size(); col++){
            if(isSafe(board, row, col)){
                board[row][col] = 'Q';
                helper(board, row+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        helper(board, 0);
        return res;
    }
};