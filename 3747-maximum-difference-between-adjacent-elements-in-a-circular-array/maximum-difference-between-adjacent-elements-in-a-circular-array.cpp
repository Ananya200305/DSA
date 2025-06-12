class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int diff = 0;
        int n = nums.size();
        int i = 0;

        do{
            diff = max(diff,abs(nums[i] - nums[(i+1)%n]));
            i = (i+1) % n;
        }while(i != 0);

        return diff;
    }
};