class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        int ans = 1; // Initialize ans to a default value

        for (int i = 2; i <= x / 2; i++) {
            if (i <= x / i) { // Avoids overflow: i*i <= x
                ans = i;
            } else {
                break;
            }
        }

        return ans;
    }
};
