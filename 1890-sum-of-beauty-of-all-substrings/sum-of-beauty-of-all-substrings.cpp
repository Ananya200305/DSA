class Solution {
public:
    int beauty(vector<int> freq){
        int minf = INT_MAX;
        int maxf = 0;
        for(int i = 0 ; i < freq.size(); i++){
            if(freq[i] > 0){
                if(maxf < freq[i]){
                    maxf = freq[i];
                }
                if(minf > freq[i]){
                    minf = freq[i];
                }
            }
        }
        return maxf - minf;
    }
    int beautySum(string s) {
        int total = 0;
        for(int i = 0; i < s.size(); i++){
            vector<int> freq(26,0);
            for(int j = i; j < s.size(); j++){
                freq[s[j] - 'a']++;
                total += beauty(freq);
            }
            
        }
        return total;
    }
};