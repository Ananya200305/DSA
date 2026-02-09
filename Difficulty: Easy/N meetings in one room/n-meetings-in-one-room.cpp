class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int, int>>ans;
        
        for(int i = 0; i < start.size(); i++){
            ans.push_back({end[i], start[i]});
        }
        
        sort(ans.begin(), ans.end());
        
        int count = 1;
        int lastEnd = ans[0].first;
        
        for(int i = 1; i < ans.size(); i++){
            if(ans[i].second > lastEnd){
                count++;
                lastEnd = ans[i].first;
            }
        }
        
        return count;
    }
};