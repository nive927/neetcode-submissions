class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int insertOne = 0;
        int ws = digits.size() - 1;

        for(int i=ws; i>=0; i--) {

            digits[i] += 1;

            if (digits[i] <= 9) { break; }

            digits[i] = 0;

            if (i == 0) { insertOne = 1; }    

        }

        if (insertOne == 1) { digits.insert(digits.begin(), 1); }

        return digits;
        
    }
};
