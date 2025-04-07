class Solution {
public:
  
    bool canPartition(vector<int>& nums) {
        int total = 0;
    for (int n : nums) total += n;
    if (total % 2 != 0) return false;
    int target = total / 2;

    unordered_set<int> sums = {0};

    for (int num : nums) {
        unordered_set<int> newSums;
        for (int s : sums) {
            if (s + num == target) return true;
            if (s + num < target) newSums.insert(s + num);
        }
        sums.insert(newSums.begin(), newSums.end());
    }

    return sums.find(target) != sums.end();
    }
};