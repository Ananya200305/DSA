class Solution {
public:
    bool isPalindrome(string s) {
        string check = "";

        for(char c : s){
            if(isalnum(c)){
                check += tolower(c);
            }
        }

        int left = 0;
        int right = check.size()-1;

        while(left <= right){
            if(check[left] != check[right]){
                cout << check[left] << " " << check[right] << endl;
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};