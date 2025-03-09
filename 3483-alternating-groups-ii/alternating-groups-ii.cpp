class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int count = 0;

        colors.insert(colors.end(), colors.begin(), colors.begin()+(k-1));

        int i = 0;
        int j = 1;

        while(j < colors.size()){
            if(colors[j] == colors[j-1]){
                i = j;
                j++;
                continue;
            }
            if(j-i+1 == k){
                count++;
                i++;
            }
            j++;
        }

        return count;
    }
};