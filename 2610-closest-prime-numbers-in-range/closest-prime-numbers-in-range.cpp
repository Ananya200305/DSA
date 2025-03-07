class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right+1, true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i*i < right+1; i++){
            if(isPrime[i] == true){
                for(int j = i*i ; j < right+1; j += i){
                    isPrime[j] = false;
                }
            }
        }

        vector<int> prime;
        for(int i = left; i < right+1; i++){
            if(isPrime[i] == true){
                prime.push_back(i);
            }
        }

        if(prime.size() < 2){
            return {-1,-1};
        }

        int minDiff = 1e6+1;
        int p1 = -1;
        int p2 = -1;

        for(size_t i = 1; i < prime.size(); i++){
            if(prime[i] - prime[i-1] < minDiff){
                minDiff = prime[i] - prime[i-1];
                p1 = prime[i-1];
                p2 = prime[i];
            }
        }

        return {p1,p2};
    }
};