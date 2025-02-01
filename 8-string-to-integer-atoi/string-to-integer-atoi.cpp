#include <climits>  // For INT_MAX and INT_MIN

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long result = 0;

        // Step 1: Ignore leading whitespaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Step 2: Handle the sign
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Check for invalid sign sequence
        if (i < s.length() && (s[i] == '+' || s[i] == '-') && i + 1 < s.length() && (s[i + 1] == '+' || s[i + 1] == '-')) {
            return 0;  // Invalid sign sequence like "+-" or "-+"
        }

        // Step 4: Convert string to integer
        while (i < s.length()) {
            if (s[i] < '0' || s[i] > '9') {
                break;  // Stop when we encounter a non-digit
            }

            result = result * 10 + (s[i] - '0');

            // Handle overflow
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;

            i++;
        }

        return result * sign;
    }
};
