class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int , int> map;
        int splits = 0;
        int splitAt = 0;

        for(int i = 0 ; i < nums.size(); i++){
            map[nums[i]]++;
        }

        int dominant = -1;
        for(const auto& pair : map){
            if(pair.second * 2 > nums.size()){
                dominant = pair.first;
            }
        }

        if(dominant == -1) return -1;

        int left = 0;
        int right = map[dominant];

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == dominant){
                left++;
                right--;
            }

            if(left * 2 > (i + 1) && right * 2 > (nums.size() - i - 1)) {
                return i; 
            }
        }
        
        return -1;
    }
};