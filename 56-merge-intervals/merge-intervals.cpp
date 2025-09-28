class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        vector<vector<int>> res;
        int n = intervals.size();

        vector<int> prev = intervals[0];

        for(int i = 1; i < n; i++){
            vector<int> interval = intervals[i];
            if(interval[0] <= prev[1]){
                prev[1] = max(prev[1], interval[1]);
            }else{
                res.push_back(prev);
                prev = interval;
            }
        }

        res.push_back(prev);

        return res;
    }
};