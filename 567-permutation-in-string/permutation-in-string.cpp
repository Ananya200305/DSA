class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        unordered_map<int, int>countS1;
        unordered_map<int, int>countS2;

        for(int i = 0 ; i < s1.length(); i++){
            countS1[s1[i]]++;
            countS2[s2[i]]++;
        }

        if(countS1 == countS2) return true;

        int left = 0; 
        for(int right = s1.length(); right < s2.length(); right++){
            countS2[s2[right]]++;
            countS2[s2[left]]--;

            if(countS2[s2[left]] == 0){
                countS2.erase(s2[left]);
            }

            left++;

            if(countS1 == countS2){
                return true;
            }
        }

        return false;
    }
};