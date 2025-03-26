class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for(auto& row : grid){
            for(int num : row){
                arr.push_back(num);
            }
        }

        sort(arr.begin(), arr.end());
        int operation = 0;

        int median = arr[arr.size()/2];

        for(auto& nums : arr){
            int diff = abs(nums - median);
            if(diff % x != 0){
                return -1;
            }
            operation += (diff/x);
        }

        return operation;
    }
};