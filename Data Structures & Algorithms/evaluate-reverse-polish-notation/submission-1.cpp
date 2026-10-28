class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        // vars
        stack<int> operands;

        // iterate the tokens
        for(int i=0; i<tokens.size(); i++) {

            // NOTE: check stack empty - add at end

            // check if its int
            if (tokens[i] != "+" &&
                tokens[i] != "-" &&
                tokens[i] != "*" &&
                tokens[i] != "/" ) {

                    // push the operands - int
                    operands.push(stoi(tokens[i]));

            // else pop the right first and then the left
                } else {
                    if (tokens[i] == "+") {

                        int right = operands.top();
                        operands.pop();
                        int left = operands.top();
                        operands.pop();

                        operands.push(left + right);
                    }
                    else if (tokens[i] == "-") {

                        int right = operands.top();
                        operands.pop();
                        int left = operands.top();
                        operands.pop();

                        operands.push(left - right);
                    }
                    else if (tokens[i] == "*") {

                        int right = operands.top();
                        operands.pop();
                        int left = operands.top();
                        operands.pop();

                        operands.push(left * right);
                    }
                    else if (tokens[i] == "/") {

                        int right = operands.top();
                        operands.pop();
                        int left = operands.top();
                        operands.pop();

                        operands.push(left / right);
                    }
                }

            

        }

        return operands.top();
        
    }
};
