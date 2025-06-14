class Solution {
public:
    int minMaxDifference(int num) {
        string nums = to_string(num);
        char ele = ' ';
        string max = "";
        string min = "";

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != '9'){
                ele = nums[i];
                break;
            } 
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(ele == nums[i]){
                max += '9';
            }else{
                max += nums[i];
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[0] == nums[i]){
                min += '0';
            }else{
                min += nums[i];
            }
        }

        return stoi(max) - stoi(min);
    }
};