class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> mapST; // Mapping from characters in s to t
        unordered_map<char, char> mapTS; // Mapping from characters in t to s

        for (int i = 0; i < s.length(); i++) {
            char charS = s[i];
            char charT = t[i];

            // Check mapping from s to t
            if (mapST.find(charS) != mapST.end()) {
                if (mapST[charS] != charT) {
                    return false; // Conflict in mapping
                }
            } else {
                mapST[charS] = charT;
            }

            // Check mapping from t to s
            if (mapTS.find(charT) != mapTS.end()) {
                if (mapTS[charT] != charS) {
                    return false; // Conflict in reverse mapping
                }
            } else {
                mapTS[charT] = charS;
            }
        }

        return true; // Strings are isomorphic
    }
};
