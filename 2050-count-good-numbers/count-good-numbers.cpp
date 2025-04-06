class Solution {
public:
    long long mod = 1e9+7;
    long long power(long long base, long long exp){
        if(exp == 0) return 1;
        long long temp = power(base, exp/2);
        temp = (temp * temp)% mod;
        if(exp % 2 == 0){
            return temp;
        }else{
            return (base* temp)% mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        return (power(5,even)*power(4,odd)) % mod;
    }
};