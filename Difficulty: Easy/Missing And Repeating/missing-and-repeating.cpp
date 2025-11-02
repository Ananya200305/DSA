class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int>freq(n+1, 0);
        
        for(int num : arr){
            freq[num]++;
        }
        
        vector<int>ans(2);
        int a = 0;
            int b = 0;
        
        for(int i = 1 ; i < freq.size(); i++){
            if(freq[i] >= 2){
                a = i;
            }
            if(freq[i] == 0){
                b = i;
            }
        }
        
        ans[0] = a;
        ans[1] = b;
        
        return ans;
    }
};