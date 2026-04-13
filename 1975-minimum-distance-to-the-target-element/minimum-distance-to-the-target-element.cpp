class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDis = INT_MAX;
        int dis = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                dis = abs(i-start);
                minDis = min(minDis, dis);
            }
        }

        return minDis;
    }
};