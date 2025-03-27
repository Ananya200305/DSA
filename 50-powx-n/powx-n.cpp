class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1; // Base case

        if (n < 0) {
            x = 1 / x;  // Convert x^(-n) to 1 / x^n
            if (n == INT_MIN) { // Handle overflow
                n = INT_MAX;
                x *= x;
            } else {
                n = -n;
            }
        }

        double half = myPow(x, n / 2); // Recursively compute x^(n/2)

        if (n % 2 == 0)
            return half * half;  // If n is even: x^n = (x^(n/2))^2
        else
            return half * half * x;  // If n is odd: x^n = (x^(n/2))^2 * x
    }
};
