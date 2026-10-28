class Solution {
public:
    double myPow(double x, int n) {
        // Base cases
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1 / x;

        // Recursive logic
        double half = myPow(x, n / 2); // Compute x^(n/2) once

        // If n is even
        if (n % 2 == 0) {
            return half * half;
        } else { // If n is odd
            return n > 0 ? half * half * x : half * half / x;
        }
    }
};
