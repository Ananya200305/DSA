class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while(n){
            int rem = n % 2;
            if(rem == 1) count++;
            n = n / 2;
        }

        return count;
    }
};