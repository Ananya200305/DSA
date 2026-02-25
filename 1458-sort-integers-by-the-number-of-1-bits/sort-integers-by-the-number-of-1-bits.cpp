class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> res;

        for(int i = 0; i < arr.size(); i++){
            int x = __builtin_popcount(arr[i]);
            res.push_back({x, arr[i]});
        }

        sort(res.begin(), res.end());

        vector<int>ans;

        for(int i = 0 ; i < res.size(); i++){
            ans.push_back(res[i].second);
        }

        return ans;
    }
};