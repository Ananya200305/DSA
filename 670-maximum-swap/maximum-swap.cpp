class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int>maxIndex(n);
        int maxI = n-1;

        for(int i = n-1; i >= 0; i--){
            if(s[i] > s[maxI]){
                maxI = i;
            }
            maxIndex[i] = maxI;
        }

        for(int i = 0; i < n; i++){
            if(s[i] < s[maxIndex[i]]){
                swap(s[i], s[maxIndex[i]]);
                return stoi(s);
            }
        }
        return num;
    }
};