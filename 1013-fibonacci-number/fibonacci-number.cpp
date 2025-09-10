class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1; 
        
        vector<int>seq(n+1,-1);

        seq[0] = 0;
        seq[1] = 1;

        for(int i = 2; i < seq.size(); i++){
            seq[i] = seq[i-1]+seq[i-2];
        }

        return seq[n];
    }
};