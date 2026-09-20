class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for(int i = 0 ; i < s.size(); i++){
            int digit = s[i] - 'a';
            int add = 26 - digit;
            int index = i + 1;
            int toAdd = add * index;
            cout << toAdd << endl;
            ans += toAdd;
        }

        return ans;
    }
};