class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();

        for(int i = 0; i < n; i++){
            bool knows = false;
            bool everyone = true;
            for(int j = 0; j < n; j++){
                if(i != j){
                    if(mat[i][j] == 1){
                        knows = true;
                    }
                    if(mat[j][i] == 0){
                        everyone = false;
                    }
                }
            }
            
            if(!knows && everyone){
                return i;
            }
            
        }

        return -1;
    }
};