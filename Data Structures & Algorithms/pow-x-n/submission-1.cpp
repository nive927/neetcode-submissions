class Solution {
public:
    double myPow(double x, int n) {

        if (n == 0) { return 1; }

        if (n == 1) { return x; }

        if (n == -1) { return 1 / x; }

        double half = myPow(x, n / 2); // Compute once and reuse

        if (n > 0) {
            if (n % 2 == 0) {
                return half * half;
            } else {
                return x * half * half;
            }
        } else {
            if (n % 2 == 0) {
                return half * half;
            } else {
                return (1 / x) * half * half;
            }
        }
    }
};
