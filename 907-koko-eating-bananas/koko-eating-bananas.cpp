class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = piles[0];

        for(int i = 0; i < piles.size(); i++){
            if(piles[i] > max){
                max = piles[i];
            }
        }

        int low = 1;
        int high = max;

        while(low < high){
            int mid = low + (high - low)/2;
            int hours = 0;
            for(int i = 0; i < piles.size(); i++){
                hours += (piles[i]+mid -1 )/mid;
            }
            if(hours <= h){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};