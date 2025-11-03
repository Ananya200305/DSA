class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int sum = 0;

        for(int i = 1; i < colors.size(); i++){
            if(colors[i] == colors[i-1]){
                sum += min(time[i], time[i-1]);
                time[i] = max(time[i], time[i-1]);
            }
        }

        return sum;
    }
};