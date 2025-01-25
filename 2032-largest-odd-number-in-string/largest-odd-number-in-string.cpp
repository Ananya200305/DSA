class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        string ans = num;


        for(int i = n-1; i >= 0; i--){
            if((num[i] - '0') % 2 == 0){
                ans.pop_back();
            }else{
                return ans;
            }
        }
        return "";
    }
};