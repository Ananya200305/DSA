class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> stringT;

        for(char c : t){
            stringT[c]++;
        }

        int have = 0;
        int need = stringT.size();
        int minLen = INT_MAX;
        int left = 0;
        int minStart = 0;

        unordered_map<char,int> window;

        for(int right = 0; right < s.length(); right++){
            char c = s[right];
            window[c]++;

            if(stringT.count(c) && window[c] == stringT[c]){
                have++;
            }

            while(have == need){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    minStart = left;
                }

                char remove = s[left];
                window[remove]--;
                if(stringT.count(remove) && window[remove] < stringT[remove]){
                    have--;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};