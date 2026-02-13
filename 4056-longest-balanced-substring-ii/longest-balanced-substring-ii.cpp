class Solution {
public:
    int one(string & s){
        int count = 1;
        int maxCount = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                count++;
            }else{
                count = 1;
            }
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }

    int two(string & s, char c1, char c2){
        int count = 0;

        unordered_map<int, int>map;
        map[0] = -1;

        int maxCount = 0;

        for(int i = 0; i < s.size(); i++){
            
            if(s[i] != c1 && s[i] != c2){
                map.clear();
                count = 0;
                map[count] = i;
                continue;
            }

            if(s[i] == c1){
                count++;
            }else{
                count--;
            }

            if(map.find(count) != map.end()){
                maxCount = max(maxCount, i - map[count]);
            }else{
                map[count] = i;
            }
        }

        return maxCount;
    }

    int three(string & s){
        vector<int>count(3, 0);

        map<vector<int>, int> map;
        map[{0,0}] = -1;

        int maxCount = 0;

        for(int i = 0 ; i < s.size(); i++){
            count[s[i] - 'a']++;

            vector<int>key = {count[2] - count[0], count[1] - count[0]};

            if(map.find(key) != map.end()){
                maxCount = max(maxCount, i - map[key]);
            }else{
                map[key] = i;
            }
        }

        return maxCount;
    }

    int longestBalanced(string s) {
        return max(three(s),(max(two(s,'b','c'),(max(two(s, 'a', 'c'),(max(one(s), two(s, 'a', 'b'))))))));
    }
};