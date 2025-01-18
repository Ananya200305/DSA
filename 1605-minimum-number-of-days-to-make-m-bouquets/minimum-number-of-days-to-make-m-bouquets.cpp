class Solution {
public:
    bool good(vector<int>& bloomDay,int day, int m, int k){
        int count = 0;
        int noofb = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                count++;
            }else{
                noofb += (count/k);
                count = 0;
            }
        }
        noofb += (count/k);
        return noofb >= m;
    };

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long value = (long long)m*k;
        if(value > bloomDay.size()) return -1;

        int low = bloomDay[0];
        int high = bloomDay[0];

        for(int i = 1; i < bloomDay.size(); i++){
            if(bloomDay[i] < low){
                low = bloomDay[i];
            }
            if(bloomDay[i] > high){
                high = bloomDay[i];
            }
        }

        while(low < high){
            int mid = low + (high - low)/2;
            if(good(bloomDay,mid,m,k)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};