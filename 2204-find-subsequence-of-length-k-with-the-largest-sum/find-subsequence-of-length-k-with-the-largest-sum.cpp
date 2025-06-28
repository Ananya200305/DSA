class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>mp;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++){
            mp.push_back({nums[i],i});
        }

        sort(mp.begin(), mp.end(), [&](const pair<int,int>&a, const pair<int,int>&b){
            return a.first > b.first;
        });

        mp.resize(k);

        sort(mp.begin(), mp.end(), [&](const pair<int,int>&a, const pair<int,int>&b){
            return a.second < b.second;
        });

        for(auto pair : mp){
            res.push_back(pair.first);
        }

        return res;
    }
};