class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        int freeDay = 0;
        int prevEnd = 0;

        for(auto& nums : meetings){
            int start = nums[0];
            int end = nums[1];

            if(prevEnd + 1 < start){
                freeDay += start - prevEnd - 1;
            }

            prevEnd = max(prevEnd, end);
        }

        freeDay += days - prevEnd;
        return freeDay;
    }
};