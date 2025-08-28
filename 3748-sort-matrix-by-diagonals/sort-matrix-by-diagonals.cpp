class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> map;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < n ;j++){
                map[i-j].push_back(grid[i][j]);
            }
        }

        for(auto & [key, value] : map){
            if(key < 0){
                sort(value.begin(), value.end());
            }else{
                sort(value.rbegin(), value.rend());
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                grid[i][j] = map[i-j].back();
                map[i-j].pop_back();
            }
        }

        return grid;
    }
};