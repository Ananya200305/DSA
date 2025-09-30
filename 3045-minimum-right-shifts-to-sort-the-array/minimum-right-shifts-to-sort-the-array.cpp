class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int breakIdx = -1;

        for(int i = 0 ; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                if(breakIdx != -1) return -1;
                breakIdx = i;
            }
        }

        if(breakIdx == -1) return 0;

        if(nums[nums.size() - 1] > nums[0]) return -1;

        return nums.size() - (breakIdx+1);
    }
};