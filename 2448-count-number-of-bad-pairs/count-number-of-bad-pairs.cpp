class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0;
        // int i = 0;
        // while(i < nums.size()){
        //     int j = i+1;
        //     while(j < nums.size()){
        //         if(i < j && ((j-i) != nums[j] - nums[i])){
        //             count++;
        //         }
        //         j++;
        //     }
        //     i++;
        // }

        unordered_map<int,long long> map;

        for(int i = 0 ; i < nums.size(); i++){
            int diff = i - nums[i];

            count += i - map[diff];

            map[diff]++;
        }

        // long long total = (long long) nums.size() * (nums.size()-1)/2;
        // long long bad = total - count;
        return count;
    }
};