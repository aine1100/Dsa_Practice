#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Parentheses {
public:
    bool isvalid(string A) {
        stack<char> s;
        for (int i = 0; i < A.size(); i++) {  // Fix loop condition
            if (A[i] == '(' || A[i] == '{' || A[i] == '[') {
                s.push(A[i]);
            } else {
                if (s.empty()) {
                    return false;
                }
                if (A[i] == ')') {
                    if (s.top() == '(') {  // Fix s.top()
                        s.pop();
                    } else {
                        return false;
                    }
                } else if (A[i] == '}') {
                    if (s.top() == '{') {  // Fix s.top()
                        s.pop();
                    } else {
                        return false;
                    }
                } else if (A[i] == ']') {
                    if (s.top() == '[') {  // Fix s.top()
                        s.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        return s.empty();
    }
};

int main() {
    string sample = "{{{}}}";
    Parentheses pr;  // Ensure class name matches
    cout << boolalpha << pr.isvalid(sample);  // Print result as true/false
    return 0;
}
