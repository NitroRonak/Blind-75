#include<bits/stdc++.h>
using namespace std;
int precedence(char &c){
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}
string infixTopostfix(string &infix){
    stack<char> st;
    string result="";
    for(int i=0; i<infix.length();i++){
        if(isalnum(infix[i])){
            result += infix[i];
        }
        else if(infix[i]=='('){
            st.push(infix[i]);
        }
        else if(infix[i]==')'){
            while(!st.empty() && st.top()!='('){
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(st.empty()) st.push(infix[i]);
            else{
                while(!st.empty() && precedence(st.top())>=precedence(infix[i])){
                    result+=st.top();
                    st.pop();
                }
                st.push(infix[i]);
            }
        }
        
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return result;
}
int main()
{
    string infix="A*(B+C)/D";
    cout<<infixTopostfix(infix)<<endl;
    return 0;
}