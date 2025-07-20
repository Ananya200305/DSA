class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // if(nums.size() == 0){
        //     return 0;
        // }

        // sort(nums.begin(), nums.end());

        // int count = 1;
        // int longest = 1;

        // for(int i = 0; i < nums.size() - 1; i++){
        //     if(nums[i] == nums[i+1]){
        //         continue;
        //     }
        //     if(nums[i] + 1 == nums[i+1]){
        //         count++;
        //     }else{
        //         longest = max(longest,count);
        //         count = 1;
        //     }
        // }
        // return max(longest,count);

        // unordered_map<int, bool> map;

        // for(int i = 0; i < nums.size(); i++){
        //     map[nums[i]] = true;
        // }

        // for(int i = 0; i < nums.size(); i++){
        //     if(map.count(nums[i] - 1) > 0){
        //         map[nums[i]] = false;
        //     }
        // }

        // int maxLen = 0;

        // for(int i = 0; i < nums.size(); i++){
        //     if(map[nums[i]] == true){
        //         int j = 0;
        //         int count = 0;
        //         while(map.count(nums[i] + j) > 0){
        //             j++;
        //             count++;
        //         }

        //         if(count > maxLen){
        //             maxLen = count;
        //         }
        //     }
        // }

        // return maxLen;

        unordered_set<int>set(nums.begin(), nums.end());

        int maxLen = 0;

        for(int num : set){
            if(set.find(num-1) == set.end()){
                int curr = num;
                int count = 1;
                while(set.count(curr+1)){
                    curr++;
                    count++;
                }

                maxLen = max(count, maxLen);
            }
        }

        return maxLen;
    }
};