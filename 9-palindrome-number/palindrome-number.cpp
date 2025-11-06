class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x > 0 && x % 10 == 0)) return false;

        long long copy = x;
        long long reverse = 0;

        while(copy){
            reverse = reverse * 10 + (copy % 10);
            copy = copy / 10;
        }

        return x == reverse;
    }
};