class Solution {
  public:
  
    void helper(vector<int>& arr, vector<int>& res, int index, int sum){
        if(index == arr.size()){
            res.push_back(sum);
            return;
        }
        
        helper(arr, res, index+1, arr[index]+sum);
        
        helper(arr, res, index+1, sum);
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        vector<int>res;
        
        helper(arr, res, 0, 0);
        
        sort(res.begin(), res.end());
        
        return res;
    }
};