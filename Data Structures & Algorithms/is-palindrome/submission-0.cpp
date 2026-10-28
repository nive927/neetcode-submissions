class Solution {
public:
    bool isPalindrome(string s) {

        string processedStr = "";

        for(int i=0; i<s.size(); i++) {
            if (isalnum(s[i])) { processedStr += tolower(s[i]); }
        }
        
        int ws = processedStr.size();

        for(int i=0, j=ws-1; i<j; i++, j--) {

            if (processedStr[i] != processedStr[j]) { return false; }

        }

        return true;

    }
};
