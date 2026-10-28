class Solution {
public:

    bool isMatching(char open, char close) {
        if (open == '(' && close == ')') { return true; }
        if (open == '[' && close == ']') { return true; }
        if (open == '{' && close == '}') { return true; }
        return false;
    }

    bool isValid(string s) {
        // Stack to store opening brackets
        stack<char> openBrackets;

        // Iterate through the string
        for (int i = 0; i < s.size(); i++) {
            // If it's an opening bracket, push it onto the stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                openBrackets.push(s[i]);
            } 
            // If it's a closing bracket
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                // Check if the stack is empty
                if (openBrackets.empty()) {
                    return false;
                }
                // Check if the top of the stack matches the current closing bracket
                if (isMatching(openBrackets.top(), s[i])) {
                    openBrackets.pop();
                } else {
                    return false;
                }
            }
        }

        // Return true if the stack is empty, meaning all brackets are matched
        return openBrackets.empty();
    }
};
