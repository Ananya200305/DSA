class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied = 0;

        for(int i = 0; i < grumpy.size(); i++){
            if(grumpy[i] == 0){
                satisfied += customers[i];
            }
        }

        int notStatisfied = 0;
        int maxNotSatisfied = 0;

        for(int i = 0; i < grumpy.size(); i++){
            if(grumpy[i] == 1){
                notStatisfied += customers[i];
            }

            if(i >= minutes && grumpy[i-minutes] == 1){
                notStatisfied -= customers[i-minutes];
            }

            maxNotSatisfied = max(maxNotSatisfied, notStatisfied);
        }

        return satisfied + maxNotSatisfied;
    }
};