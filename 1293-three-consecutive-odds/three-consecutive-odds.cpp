class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i = 0;

        while(i + 2 < arr.size()){
            if((arr[i] & 1) && (arr[i+1] & 1) && (arr[i+2] & 1)){
                return true;
            }

            if(!(arr[i+2] & 1)){
                i += 3;
            }else if(!(arr[i+1] & 1)){
                i += 2;
            }else{
                i++;
            }
        }

        return false;
    }
};