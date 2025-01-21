//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int size = a.size() + b.size();
        vector<int> arr(size);
        // int number;
        
        int i = 0;
        int p1 = 0;
        int p2 = 0;
        
        while(p1 < a.size() && p2 < b.size()){
            if(a[p1] <= b[p2]){
                arr[i] = a[p1];
                p1++;
                i++;
            }
            if(a[p1] >= b[p2]){
                arr[i] = b[p2];
                p2++;
                i++;
            }
        }
        
        while(p1 < a.size()){
            arr[i] = a[p1];
            i++;
            p1++;
        }
        
        while(p2 < b.size()){
            arr[i] = b[p2];
            i++;
            p2++;
        }
        
        return arr[k-1];
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends