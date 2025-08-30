class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> boxes[9];

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char c = board[i][j];
                if(c == '.') continue;
                int idx = (i/3)*3 + (j/3);
                if(row[i].count(c) || col[j].count(c) || boxes[idx].count(c)) return false;
                row[i].insert(c);
                col[j].insert(c);
                boxes[idx].insert(c);
            }
        }

        return true;
    }
};