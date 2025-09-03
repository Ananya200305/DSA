class Solution {
public:
    bool nothasDuplicate(string & s1, string & s2){
        vector<int>count(26,0);

        for(char c : s1){
            count[c - 'a']++;
        }

        for(char c : s2){
            count[c - 'a']++;
        }

        for(int c : count){
            if(c > 1) return false;
        }

        return true;
    }
    int helper(vector<string>& arr, string temp, int i){
        if(i >= arr.size()) return temp.size();

        int include = 0;
        int exclude = 0;

        if(nothasDuplicate(arr[i], temp)){
            include = helper(arr, temp+arr[i], i+1);
            exclude = helper(arr, temp , i+1);
        }else{
            exclude = helper(arr, temp , i+1);
        }

        return max(include , exclude);
    }
    int maxLength(vector<string>& arr) {
        string temp = "";

        int i = 0;

        return helper(arr, temp, i);
    }
};