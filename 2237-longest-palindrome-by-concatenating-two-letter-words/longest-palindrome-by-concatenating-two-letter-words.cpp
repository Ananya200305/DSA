class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int len = 0;
        bool hasCenter = false;

        for(string s : words){
            mp[s]++;
        }

        for(auto& pair : mp){
            string word = pair.first;
            int freq = pair.second;
            string rev = word;
            reverse(rev.begin(), rev.end());

            if(word != rev && mp.find(rev) != mp.end()){
                int pairs = min(freq, mp[rev]);
                len += pairs*4;
                mp[word] -= pairs;
                mp[rev] -= pairs;
            }
        }

        for(auto& pair : mp){
            string word = pair.first;
            int freq = pair.second;

            if(word[0] == word[1]){
                len += (freq / 2) * 4;
                if(freq % 2 == 1 && !hasCenter){
                    len += 2;
                    hasCenter = true;
                }
            }
        }

        return len;
    }
};