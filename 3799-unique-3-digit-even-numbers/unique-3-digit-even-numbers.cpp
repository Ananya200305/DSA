class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>freq(10,0);
        int unique = 0;

        for(int d : digits){
            if(d && freq[d] == 0){
                unique++;
            }
            freq[d]++;
        }

        int ans = 0;

        for(int i = 0; i < 10; i+=2){
            if(freq[i] == 0){
                continue;
            }

            for(int j = 0; j < 10; j++){
                if(freq[j] == 0 || (i == j && freq[i] < 2)){
                    continue;
                }

                int k = unique;

                if(i != j){

                    if(freq[i] < 2 && i){
                        k--;
                    }

                    if(freq[j] < 2 && j){
                        k--;
                    }
                }else{

                    if(i && freq[i] < 3){
                        k--;
                    }
                }

                ans += max(0, k);
            }
        }

        return ans;
    }
};