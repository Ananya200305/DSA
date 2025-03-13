class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), prefix = 0, k = 0;
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++) {
            while (prefix + freq[i] < nums[i]) {
                if (k == queries.size()) return -1;
                int l = queries[k][0];
                int r = queries[k][1];
                int val = queries[k][2];
                k++;
                
                if (r < i) continue;
                freq[max(l, i)] += val;
                freq[r + 1] -= val;
            }
            prefix += freq[i];
        }
        return k;
    }
};