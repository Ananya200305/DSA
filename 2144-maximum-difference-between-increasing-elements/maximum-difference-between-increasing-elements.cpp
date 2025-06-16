class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1;

        for(int i = 0 ; i < (nums.size()-1); i++){
            int a = nums[i];
            for(int j = i+1; j < nums.size(); j++){
                int b = nums[j];
                if(a < b){
                    int diff = b - a;
                    maxDiff = max(diff, maxDiff);
                }
            }
        }

        return maxDiff;
    }
};