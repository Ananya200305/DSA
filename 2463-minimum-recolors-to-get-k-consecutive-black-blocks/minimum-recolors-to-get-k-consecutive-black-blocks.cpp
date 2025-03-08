class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int black_count = 0;
        int ans;

        for(int i = 0; i < k; i++){
            if(blocks[i] == 'B'){
                black_count++;
            }
        }

        ans = k - black_count;

        for(int i = k ; i < blocks.size(); i++){
            if(blocks[i-k] == 'B'){
                black_count--;
            }
            if(blocks[i] == 'B'){
                black_count++;
            }
            ans = min(ans, k - black_count);
        }

        return ans;
    }
};