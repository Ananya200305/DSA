class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int shift = 0;
        long long len = 1;
        vector<long long>length;

        for(int op : operations){
            len = len * 2;
            length.push_back(len);
            if(len >= k) break;
        }

        for(int j = length.size()-1; j >= 0; j--){
            long long half = length[j]/2;
            int op = operations[j];
            if(k > half){
                k = k - half;
                if(op == 1){
                    shift++;
                }
            }
        }

        return (char) ((('a' - 'a' + shift) % 26) + 'a');
    }
};