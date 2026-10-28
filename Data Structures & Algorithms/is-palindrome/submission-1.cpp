class Solution {
public:
    bool isPalindrome(string s) {
        
        // Constraints:
        // input: sting
        // output: bool

        /*
        LOGIC:
        Preprocessing:
        - convert to all lower-case
        - remove non-alphanumeric characters
        
        Two pointers:
        - l & r from the start & end respectively till they meet in the middle
        - simultaneously compare characters
        - return false if not matching
        - once loop is complete, return true
        */

        /*
        COMPLEXITY:
        time: O(n) - 2 loops linearly
        space: O(n) - string reconstruction
        */

        // Preprocessing
        string cleaned = "";
        for(auto c: s) {

            if(isalnum(c)) {
                cleaned += tolower(c);
            }
            
        }

        for(int l=0, r=cleaned.size()-1; l<=r; l++, r--) {
            if(cleaned[l] != cleaned[r]) {
                return false;
            }
        }

        return true;

    }
};
