class Solution {
  public:
    int findMin(int n) {
        int count = 0;
        vector<int>denomination = {1,2,5,10};
        
        for(int i = denomination.size()-1; i >= 0; i--){
            while(n >= denomination[i]){
                n = n - denomination[i];
                count++;
            }
        }
        
        return count;
    }
};