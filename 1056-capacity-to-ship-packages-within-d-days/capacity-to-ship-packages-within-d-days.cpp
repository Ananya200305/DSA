class Solution {
public:
    int days1(vector<int>& weights, int capacity){
        int day = 1;
        int load = 0;
        for(int i = 0; i < weights.size(); i++){
            if(load + weights[i] > capacity){
                day = day+1;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = weights[0];
        int high = 0;
        for(int i = 0; i < weights.size(); i++){
            if(weights[i] > low){
                low = weights[i];
            }
            high += weights[i];
        }
        while(low < high){
            int mid = low + (high - low)/2;
            int dayreq = days1(weights,mid);
            if(dayreq <= days){
                high = mid;
            }else if(dayreq > days){
                low = mid + 1;
            }
        }
        return high;
    }
};