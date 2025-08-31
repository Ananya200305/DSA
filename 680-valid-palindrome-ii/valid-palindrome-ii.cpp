class Solution {
public:
    bool isPal(string & s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true;
    }
    bool validPalindrome(string s) {
        bool del = false;
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }else{
                if(!del){
                    return isPal(s, left+1, right) || isPal(s, left, right-1);
                }else{
                    return false;
                }
            }
        }

        return true;
    }
};