class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missing = 0;
        int index = 0;
        int current = 1;

        while(true){
            if(index < arr.size() && arr[index] == current){
                index++;
            }else{
                missing++;
                if(missing == k){
                    return current;
                }
            }
            current++;
        }
    }
};
