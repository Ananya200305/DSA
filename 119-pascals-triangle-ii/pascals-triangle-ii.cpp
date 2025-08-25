class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex+1;

        vector<vector<int>>triangle(n);

        for(int i = 0; i < n; i++){
            triangle[i] = vector<int>(i+1, 1);
            for(int j = 1; j < i; j++){
                triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
            }
        }

        return triangle[rowIndex];
    }
};