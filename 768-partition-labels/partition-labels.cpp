class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26,0);
        for(int i = 0; i < s.size(); i++){
            last[s[i] - 'a'] = i;
        }

        vector<int> partition;
        int start = 0;
        int end = 0;

        for(int i = 0; i < s.size(); i++){
            end = max(end, last[s[i] - 'a']);

            if(i == end){
                partition.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return partition;
    }
};