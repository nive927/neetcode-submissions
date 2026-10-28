class Solution {
public:

    vector<string> ans;

    // mapping the digits to the pressable characters
    // 0, 1 enter nothing
    // 2-9 are assigned the alphabetical characters
    vector<string> mapper = {"",
                             "",
                             "abc",
                             "def",
                             "ghi",
                             "jkl", 
                             "mno",
                             "qprs",
                             "tuv",
                             "wxyz"};


    void backtrack(int index, string curr, string digits) {

        if(digits.empty()) {
            return;
        }

        if(curr.size() == digits.size()) {
            ans.push_back(curr);
            return;
        }

        for(int i=index; i<digits.size(); i++) {

            for(auto c: mapper[digits[i] - '0']) {

                backtrack(i+1, curr+c, digits);

            }

        }

    }

    vector<string> letterCombinations(string digits) {

        string curr;
        backtrack(0, curr, digits);
        return ans;
        
    }
};
