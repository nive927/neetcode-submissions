class Solution {
public:

    bool isPalindrome(string s) {
        for(int i=0, j=s.size()-1; i<s.size()/2; i++, j--) {
            if(s[i] != s[j]) {
                return false;
            }
        }

        return true;
    }
    string firstPalindrome(vector<string>& words) {

        for(auto word: words) {
            if(isPalindrome(word)) {
                return word;
            }
        }

        return "";

    }
};
