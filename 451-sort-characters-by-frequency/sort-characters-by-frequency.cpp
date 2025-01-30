class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency of each character using a hash map
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Create a vector of characters and their frequencies
        vector<pair<int, char>> freqArr;
        for (auto& entry : freq) {
            freqArr.push_back({entry.second, entry.first});
        }

        // Step 3: Sort the vector by frequency in descending order
        sort(freqArr.rbegin(), freqArr.rend());

        // Step 4: Build the result string by appending characters based on frequency
        string ans = "";
        for (auto& p : freqArr) {
            ans.append(p.first, p.second);  // Append character p.first times
        }

        return ans;
    }
};

