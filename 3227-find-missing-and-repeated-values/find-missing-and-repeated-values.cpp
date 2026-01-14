class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int>res(n*n+1, 0);

        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                res[grid[i][j]]++;
            }
        }

        vector<int>ans(2);

        for(int i = 1 ; i < res.size(); i++){
            if(res[i] == 0) ans[1] = i;
            if(res[i] == 2) ans[0] = i;
        }

        return ans;
    }
};