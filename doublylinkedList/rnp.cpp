#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Rpn {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                // Pop two elements from the stack
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();

                // Perform the corresponding operation
                if (tokens[i] == "+") {
                    st.push(v2 + v1);
                } else if (tokens[i] == "-") {
                    st.push(v2 - v1);
                } else if (tokens[i] == "*") {
                    st.push(v2 * v1);
                } else if (tokens[i] == "/") {
                    st.push(v2 / v1);
                }
            } else {
                // Convert the operand to an integer and push it to the stack
                st.push(stoi(tokens[i]));
            }
        }

        // The final result is the top element of the stack
        return st.top();
    }
};

int main() {
    // Example input
    vector<string> tokens = {"2", "1", "+", "3", "*"}; // Equivalent to (2 + 1) * 3 = 9
    Rpn rpn;
    cout << "Result: " << rpn.evalRPN(tokens) << endl; // Output: 9
    return 0;
}
