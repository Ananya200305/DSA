class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>vowels;
        unordered_map<char,int>consonant;
        int maxV = 0;
        int maxC = 0;

        for(char ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                vowels[ch]++;
                maxV = max(maxV, vowels[ch]);
            }else{
                consonant[ch]++;
                maxC = max(maxC, consonant[ch]);
            }
        }

        

        return maxV+maxC;
    }
};