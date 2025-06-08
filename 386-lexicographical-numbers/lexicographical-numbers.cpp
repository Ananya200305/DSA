class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result(n);

        int x = 1;

        for(int i = 0; i < n; i++){
            result[i] = x;
            if(x*10 > n){
                if(x == n){
                    x = x/10;
                }
                x++;
                while(x%10 == 0){
                    x = x / 10;
                }
            }else{
                x = x * 10;
            }
        }

        return result;
    }
};