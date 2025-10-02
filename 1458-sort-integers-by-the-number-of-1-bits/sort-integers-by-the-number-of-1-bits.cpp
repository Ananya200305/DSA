class Solution {
public:
    int helper(int n){
        int count = 0;

        while(n){
            count += n & 1;
            n = n >> 1;
        }
        
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>>res;

        for(int i = 0 ; i < arr.size(); i++){
            int x = helper(arr[i]);
            cout << x << endl;
            res.push_back({x, arr[i]});
        }

        sort(res.begin(), res.end());

        vector<int> ans;

        for(int i = 0 ; i < res.size(); i++){
            ans.push_back(res[i].second);
        }

        return ans;
    }
};