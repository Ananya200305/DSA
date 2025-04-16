class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        // for(int i = 0; i <= n ; i++){
        //     int temp = i;
        //     int count = 0;
        //     while(temp > 0){
        //         if(temp % 2 == 1) count++;
        //         temp = temp / 2;
        //     }
        //     result.push_back(count);
        // }

        for(int i = 1; i <= n; i++){
            result[i] = result[i >> 1] + (i & 1);
        }
        return result;
    }
};