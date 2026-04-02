class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int highest = piles[0];

        for(int i = 0; i < piles.size(); i++){
            if(piles[i] > highest){
                highest = piles[i];
            }
        }

        int left = 1;
        int right = highest;

        while(left < right){
            int mid = left + (right - left)/2;
            int hours = 0;
            for(int i = 0; i < piles.size(); i++){
                hours += (piles[i]+mid-1)/mid;
            }
            if(hours <= h){
                right = mid;
            }else{
                left = mid + 1;
            }
        }

        return left;
    }
};