//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Helper function to count substrings with at most k distinct characters
    int atMostKDistinct(string& s, int k) {
        if (k == 0) return 0;
        unordered_map<char, int> freq;
        int left = 0, right = 0, count = 0;

        while (right < s.size()) {
            freq[s[right]]++; // Expand window by adding new character

            while (freq.size() > k) {  // Shrink window if distinct characters exceed k
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);
                left++;
            }
            
            count += (right - left + 1); // Count valid substrings in current window
            right++;
        }
        return count;
    }

    int countSubstr(string& s, int k) {
        return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends