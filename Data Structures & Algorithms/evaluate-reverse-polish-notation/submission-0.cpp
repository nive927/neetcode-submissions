#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Stack to store operands
        stack<int> operands;

        // Iterate through the tokens
        for (const string& token : tokens) {
            // Check if the token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop the right operand first
                int right = operands.top();
                operands.pop();
                // Pop the left operand
                int left = operands.top();
                operands.pop();

                // Perform the operation and push the result back onto the stack
                if (token == "+") {
                    operands.push(left + right);
                } else if (token == "-") {
                    operands.push(left - right);
                } else if (token == "*") {
                    operands.push(left * right);
                } else if (token == "/") {
                    operands.push(left / right);
                }
            } else {
                // If the token is not an operator, it must be a number
                operands.push(stoi(token));
            }
        }

        // The result will be the only value left in the stack
        return operands.top();
    }
};
