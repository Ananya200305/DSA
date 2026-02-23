class Solution {
public:
    bool isPrime(int x){
        if(x < 2) return false;

        for(int i = 2; i*i <= x; i++){
            if(x % i == 0) return false;
        }

        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int count = 0;

        for(int i = left; i <= right; i++){
            int num = i;
            string res = "";

            while(num > 0){
                char ch = (num % 2) + '0';
                res.push_back(ch);
                num = num / 2;
            }

            reverse(res.begin(), res.end());

            int setBit = 0;
            for(char c : res){
                if(c == '1') setBit++;
            }

            if(isPrime(setBit)) count++;
        }

        return count;
    }
};