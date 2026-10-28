class Solution {
public:

    int sumOfDigits(int n) {
        
        int sum = 0;
        
        while (n > 0) {

            sum += pow((n % 10), 2);
            n /= 10;

        }
        
        return sum;

    }

    bool isHappy(int n) {


        unordered_set<int> seen;

        int currSum = sumOfDigits(n);

        if (currSum == 1) { return true; }

        while (currSum != 1) {

            currSum = sumOfDigits(currSum);

            if (currSum == 1) { return true; }

            if (seen.find(currSum) != seen.end()) { return false; }

            seen.insert(currSum);

        }

        return true;

        
        
    }
};
