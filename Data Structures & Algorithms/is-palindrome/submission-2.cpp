class Solution {
public:
    bool isPalindrome(string s) {

        for (int l = 0, r = s.size() - 1; l < r; l++, r--) {

            // Skip non-alphanumeric from left
            while (l < r && !isalnum(s[l])) l++;

            // Skip non-alphanumeric from right
            while (l < r && !isalnum(s[r])) r--;

            // Compare lowercase characters
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
        }

        return true;
    }
};
