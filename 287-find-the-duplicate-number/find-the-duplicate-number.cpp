class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        vector<int>res(n+1, 0);

        for(int i = 0 ; i < n; i++){
            if(res[nums[i]] == 1){
                return nums[i];
            }

            res[nums[i]]++;
        }

        return 0;
    }
};