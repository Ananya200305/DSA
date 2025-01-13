//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        int low = 1;
        int high = n;
        
        while(low <= high){
            int mid = (high+low)/2;
            int value = mid*mid;
            if(value <= n){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends