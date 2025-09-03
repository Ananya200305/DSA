class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i = 0;
        int j = 0;
        int n = start.size();
        int maxRoom = 0;
        int room = 0;
        
        while(i < n && j < n){
            if(start[i] < end[j]){
                room++;
                maxRoom = max(room, maxRoom);
                i++;
            }else{
                room--;
                j++;
            }
        }
        
        return maxRoom;
    }
};
