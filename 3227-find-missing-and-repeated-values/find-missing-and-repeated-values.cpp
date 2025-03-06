class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<int> array(n*n+1,0);

        vector<int> result(2);

        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n; j++){
                array[grid[i][j]]++;
            }
        }

        for(int i = 0 ; i < array.size(); i++){
            if(array[i] == 2){
                result[0] = i;
            }
            if(array[i] == 0){
                result[1] = i;
            }
        }

        return result;
    }
};