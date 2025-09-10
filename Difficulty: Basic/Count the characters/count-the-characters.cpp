
class Solution {
  public:
    int getCount(string S, int N) {
        vector<int>count(26,0);
        
        char prev = '\0';
        
        for(char c : S){
            if(c != prev){
                count[c - 'a']++;
            }
            prev = c;
        }
        
        int result = 0;
        
        for(int c : count){
            if(c == N){
                result++;
            }
        }
        
        return result;
        
    }
};