class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        vector<int> res(row * col);
        int r = 0, c = 0;

        for (int i = 0; i < res.size(); i++) {
            res[i] = mat[r][c];

            if ((r + c) % 2 == 0) { // moving up
                if (c == col - 1) { // last column → move down
                    r++;
                } else if (r == 0) { // first row → move right
                    c++;
                } else { // normal up-right move
                    r--;
                    c++;
                }
            } else { // moving down
                if (r == row - 1) { // last row → move right
                    c++;
                } else if (c == 0) { // first col → move down
                    r++;
                } else { // normal down-left move
                    r++;
                    c--;
                }
            }
        }

        return res;
    }
};
