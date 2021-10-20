#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens){
    int n=tokens.size(),a=0,b=0;
    stack<int> oper;

    for(int i=0; i<n;i++){
        if(tokens[i]=="*"){
            a=oper.top();
            oper.pop();
            b=oper.top();
            oper.pop();
            oper.push(a*b);
        }
        else if(tokens[i]=="-"){
            a=oper.top();
            oper.pop();
            b=oper.top();
            oper.pop();
            oper.push(b-a);
        }
        else if(tokens[i]=="/"){
            a=oper.top();
            oper.pop();
            b=oper.top();
            oper.pop();
            oper.push(b/a);
        }
        else if(tokens[i]=="+"){
            a=oper.top();
            oper.pop();
            b=oper.top();
            oper.pop();
            oper.push(b+a);
        }
        else if(tokens[i]>="0" || tokens[i]<="9"){
            oper.push(stoi(tokens[i]));
        }
    }
    return oper.top();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> tokens={"2","1","+","3","*"};

    cout<<evalRPN(tokens);

    return 0;
}