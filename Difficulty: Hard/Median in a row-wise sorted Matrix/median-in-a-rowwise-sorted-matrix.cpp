//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int i = 0;
        int j = 0;
        int k = 0;
        int median;
        
        int row = mat.size();
        int col = mat[0].size();
        
        int size = row * col;
        vector<int> arr(size);
        
        while(i < row){
            int j = 0;
            while(j < col){
                arr[k] = mat[i][j];
                k++;
                j++;
            }
            i++;
        }
        
        sort(arr.begin(),arr.end());
        int low = 0;
        int high = arr.size() -1;
        int mid = low + (high - low)/2;
        
        if(size % 2 == 0){
            median = (arr[mid] + arr[mid+1])/2;
        }else{
            median = arr[mid];
        }
        return median;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends