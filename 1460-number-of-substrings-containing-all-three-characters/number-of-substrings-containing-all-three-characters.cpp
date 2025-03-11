class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> count(3,0);

        int i = 0;
        int j = 0;
        int result = 0;

        while(j < n){
            count[s[j] - 'a']++;

            while(count[0] > 0 && count[1] > 0 && count[2] > 0){
                result = result + (n-j);
                count[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return result;
    }
};