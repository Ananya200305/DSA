class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0)) return false;

        long long reverse = 0;
        long long copy = x;

        while(copy){
            reverse = reverse * 10 + (copy % 10);
            copy = copy / 10;
        }

        cout << reverse << endl;
        return x == reverse;
    }
};