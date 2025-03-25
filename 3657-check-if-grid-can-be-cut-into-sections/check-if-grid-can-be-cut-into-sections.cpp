class Solution {
public:
    bool check(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int sections = 0;
        int max_end = intervals[0][1];
        
        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            if (max_end <= start) {
                sections++;
            }
            max_end = max(max_end, end);
        }
        
        return sections >= 2;
    }
    
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x, y;
        
        for (auto& rectangle : rectangles) {
            x.push_back({rectangle[0], rectangle[2]});
            y.push_back({rectangle[1], rectangle[3]});
        }
        
        return check(x) || check(y);
    }
};