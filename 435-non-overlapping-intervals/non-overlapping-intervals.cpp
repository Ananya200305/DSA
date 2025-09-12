class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        vector<int> prev = intervals[0];

        int count = 0;

        for(int i = 1; i < intervals.size(); i++){
            vector<int>interval = intervals[i];
            if(prev[1] > interval[0]){
                count++;
                prev[1] = min(prev[1], interval[1]);
            }else{
                prev = interval;
            }
        }

        return count;
    }
};