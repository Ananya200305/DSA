class Solution {
public:
    bool possiblePartition(string& s, int index, int target){
        if(index == s.size()) return target == 0;

        int sum = 0;

        for(int i = index; i < s.size(); i++){
            sum = sum * 10 + (s[i] - '0');
            if(sum > target) return false;
            if(possiblePartition(s, i+1, target - sum)){
                return true;
            };
        }
        return false;
    }
    int punishmentNumber(int n) {
        int result = 0;

        for(int i = 1; i <= n; i++){
            int square = i*i;
            string stringSquare = to_string(square);
            if(possiblePartition(stringSquare,0,i)){
                result = result + square;
            }
        }

        return result;
    }
};