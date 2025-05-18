class Solution {
public:
    // Helper function to calculate digit sum
    static int sumdigit(int num){
        num = abs(num);
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);  // Make a copy

        // Sort by digit sum, then value
        sort(sorted.begin(), sorted.end(), [](int a, int b){
            int sa = sumdigit(a);
            int sb = sumdigit(b);
            return (sa == sb) ? a < b : sa < sb;
        });

        // Map value to its index in sorted array
        unordered_map<int, int> sortedIndex;
        for(int i = 0; i < n; i++){
            sortedIndex[sorted[i]] = i;
        }

        // Track visited elements
        vector<bool> visited(n, false);
        int swaps = 0;

        // Cycle detection
        for (int i = 0; i < n; ++i) {
            if (visited[i] || sortedIndex[nums[i]] == i)
                continue;

            int j = i;
            int cycle_size = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = sortedIndex[nums[j]];
                cycle_size++;
            }

            if (cycle_size > 1)
                swaps += (cycle_size - 1);
        }

        return swaps;
    }
};
