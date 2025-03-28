class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> result;

        int count1 = 0;
        int count2 = 0;

        int ele1 = INT_MIN;
        int ele2 = INT_MIN;

        for(int i = 0 ; i < nums.size(); i++){
            if(count1 == 0 && ele2 != nums[i]){
                count1 = 1;
                ele1 = nums[i];
            }else if(count2 == 0 && ele1 != nums[i]){
                count2 = 1;
                ele2 = nums[i];
            }else if(nums[i] == ele1){
                count1++;
            }else if(nums[i] == ele2){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == ele1) count1++;
            if(nums[i] == ele2) count2++;
        }

        int majority = int(nums.size()/3) + 1;

        if(majority <= count1) result.push_back(ele1);
        if(majority <= count2) result.push_back(ele2);

        return result;
    }
};