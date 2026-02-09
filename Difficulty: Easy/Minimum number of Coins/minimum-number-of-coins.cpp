class Solution {
  public:
    int findMin(int n) {
        // code here
        int count = 0;
        vector<int>d = {1,2,5,10};
        
        for(int i = d.size()-1; i >= 0; i--){
            while(n >= d[i]){
                count++;
                n = n - d[i];
            }
        }
        
        return count;
    }
};