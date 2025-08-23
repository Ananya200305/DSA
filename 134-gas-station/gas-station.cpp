class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();

        int res = 0;
        int total = 0;
        int tank = 0;

        for(int i = 0; i < n ; i++){
            tank += gas[i] - cost[i];
            total += gas[i] - cost[i];

            if(tank < 0){
                res = i+1;
                tank = 0;
            }
        }

        if(total >= 0) return res % (n+1);
        else return -1;
    }
};