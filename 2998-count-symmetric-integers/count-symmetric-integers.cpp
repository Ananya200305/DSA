class Solution {
public:
    bool isSymmetric(int num){
        string s = to_string(num);
        int length = s.length();

        if(length % 2 != 0){
            return false;
        }

        int half = length/2;
        int first = 0;
        int second = 0;

        for(int i = 0; i < half; i++){
            first = first + (s[i] - '0');
        }

        for(int i = half; i < length; i++){
            second = second + (s[i] - '0');
        }

        return first == second;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; i++){
            if(isSymmetric(i)){
                count++;
            }
        }
        return count;
    }
};