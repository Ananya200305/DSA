class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>row[9];
        unordered_set<char>col[9];
        unordered_set<char>box[9];

        for(int i = 0 ; i < 9; i++){
            for(int j = 0 ; j < 9; j++){
                char ch = board[i][j];
                if(ch == '.') continue;
                int idx = (i/3)*3 + (j/3);

                if(row[i].count(ch) || col[j].count(ch) || box[idx].count(ch)) return false;

                row[i].insert(ch);
                col[j].insert(ch);
                box[idx].insert(ch);
            }
        }

        return true;
    }
};