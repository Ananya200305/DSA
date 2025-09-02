class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count;

        for(int num : nums){
            count[num]++;
        }

        vector<vector<int>> freq(nums.size() + 1);
        for(auto& pair : count){
            int val = pair.first;
            int f = pair.second;
            freq[f].push_back(val);
        }

        vector<int>ans;
        for(int i = freq.size()-1; i>= 0; i--){
            for(int n : freq[i]){
                ans.push_back(n);
                if(ans.size() == k){
                    return ans;;
                }
            }
        }

        return {};
    }
};