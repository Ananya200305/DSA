class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    //     return nums[nums.size()/2];
    // } O(n logn)

    // O(n) - Boyer - Moore Voting Algo

        int count = 1;
        int candidate = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(count == 0){
                candidate = nums[i];
                count = 1;
            }else if(candidate == nums[i]){
                count++;
            }else{
                count--;
            }
        }
        return candidate;
    }
};