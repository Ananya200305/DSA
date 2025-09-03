class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        
        sort(arr.begin(), arr.end(),[](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        
        vector<int>prev = arr[0];
        
        for(int i = 1 ; i < arr.size(); i++){
            vector<int> interval = arr[i];
            
            if(interval[0] >= prev[1]){
                prev = interval;
            }else{
                return false;
            }
        }
        
        return true;
    }
};