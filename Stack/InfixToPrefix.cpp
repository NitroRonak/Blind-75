#include<bits/stdc++.h>
using namespace std;

bool isOperatorOrParenthesis(char c) {
    return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-' || c == '(' || c == ')');
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string infixToPrefix(std::string &infix) {
    stack<char> st;
    string result = "";

    for (int i = infix.length() - 1; i >= 0; i--) {
        if (isOperatorOrParenthesis(infix[i])) {
            if (infix[i] == ')') {
                st.push(infix[i]);
            } else if (infix[i] == '(') {
                while (!st.empty() && st.top() != ')') {
                    result += st.top();
                    st.pop();
                }
                st.pop();  // Discard the corresponding ')'
            } else {
                if (st.empty()) st.push(infix[i]);
                else {
                    while (!st.empty() && precedence(st.top()) >= precedence(infix[i])) {
                        result += st.top();
                        st.pop();
                    }
                    st.push(infix[i]);
                }
            }
        } else {
            result += infix[i];
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string infix="a*(b+c+d)";
    cout<<infixToPrefix(infix)<<endl;
    return 0;
}