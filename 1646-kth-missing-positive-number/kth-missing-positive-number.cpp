class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missing = 0;
        int current = 1;
        int index = 0;

        // Loop until we find the kth missing positive number
        while (true) {
            // If the current number is missing in the array
            if (index < arr.size() && arr[index] == current) {
                index++;  // Move to the next element in the array
            } else {
                missing++;  // Count this number as missing
                if (missing == k) {
                    return current;  // If it's the kth missing, return it
                }
            }
            current++;  // Move to the next number
        }
    }
};
