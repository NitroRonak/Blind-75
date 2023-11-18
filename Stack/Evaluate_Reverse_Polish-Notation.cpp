#include<bits/stdc++.h>
using namespace std;
int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(auto x:tokens){
        if(x=="+" || x=="-" || x=="/" || x=="*"){
            int op2=st.top(); 
            st.pop();
            int op1=st.top(); 
            st.pop();
            if(x=="+") st.push(op1+op2);
            else if(x=="-") st.push(op1-op2);
            else if(x=="/") st.push(op1/op2);
            else st.push(op1*op2);
        }
        else{
            stringstream ss(x);
            int data;
            ss>>data;
            st.push(data);
        }
    }
    return st.top();
}

int main()
{
    vector<string> tokens{"2","1","+","3","*"};
    cout<<evalRPN(tokens)<<endl;
    return 0;
}