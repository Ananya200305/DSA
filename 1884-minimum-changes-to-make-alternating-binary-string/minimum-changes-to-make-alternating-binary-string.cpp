class Solution {
public:
    int minOperations(string s) {
        string zero = "0";
        string one = "1";

        int n = s.size();

        for(int i = 1; i < n; i++){
            if(zero[i-1] == '0'){
                zero.push_back('1');
            }else{
                zero.push_back('0');
            }

            if(one[i-1] == '1'){
                one.push_back('0');
            }else{
                one.push_back('1');
            }
        }

        int count0 = 0;
        int count1 = 0;

        for(int i = 0; i < n; i++){
            if(s[i] != zero[i]){
                count0++;
            }

            if(s[i] != one[i]){
                count1++;
            }
        }

        return min(count0, count1);
    }
};