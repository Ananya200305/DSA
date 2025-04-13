class Solution {
public:
    string smallestPalindrome(string s) {
        
        vector<int> freq(26,0);
        for(int i = 0; i < s.length(); i++){
            freq[s[i] - 'a']++;
        }

        string left = "";
        int mid = 0;

        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 != 0){
                if(mid == 0){
                    mid = i + 'a';
                }else{
                    return "";
                }
            }
            left += string(freq[i]/2, i+'a');
        }

        string right = left;
        reverse(right.begin(),right.end());

        return left + ((mid != 0) ? string(1,mid) : "") + right;
    }
};