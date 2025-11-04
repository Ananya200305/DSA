class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;

        for(int i = 0; i <= nums.size()-k; i++){
            vector<int>subarr(nums.begin() + i, nums.begin()+k+i);
            unordered_map<int, int>map;

            for(int sub : subarr){
                map[sub]++;
            }

            if(map.size() < x){
                int s = 0;
                for(int i = 0; i < subarr.size(); i++){
                    s += subarr[i];
                }

                res.push_back(s);
                continue;
            }

            vector<pair<int, int>>pairs(map.begin(), map.end());

            sort(pairs.begin(), pairs.end(), [](auto & a, auto & b){
                if(a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });

            int sum = 0;
            int limit = min(x, (int)pairs.size());

            for(int i = 0 ; i < limit; i++){
                sum += (pairs[i].first * pairs[i].second);
            }

            res.push_back(sum);
        }

        return res;
    }
};