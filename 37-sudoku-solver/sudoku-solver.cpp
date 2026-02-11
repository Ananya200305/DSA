class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char num){
        for(int i = 0; i < 9; i++){
            if(board[i][col] == num) return false;
            if(board[row][i] == num) return false;
        }

        int startRow = (row/3)*3;
        int startCol = (col/3)*3;

        for(int i = startRow; i < startRow + 3; i++){
            for(int j = startCol; j < startCol + 3; j++){
                if(board[i][j] == num) return false;
            }
        }

        return true;
    }
    bool helper(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    for(char num = '1' ; num <= '9'; num++){
                        if(isSafe(board, i , j, num)){
                            board[i][j] = num;
                            if(helper(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};