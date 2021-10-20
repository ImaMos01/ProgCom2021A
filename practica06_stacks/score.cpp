#include <bits/stdc++.h>
using namespace std;

int scoreOfParentheses(string s){
    stack<string> oper;
    int a=0,b=0;
    for(int i=0; i<s.length();i++){
        if(s[i]=='('){
            string arr(1,s[i]);
            oper.push(arr);
        }
        else if(s[i]==')'){
            if(oper.top()=="("){
                oper.pop();
                oper.push("1");
            }
            else{
                a= stoi(oper.top());
                oper.pop();
    
                while(oper.top()!="("){
                    a+=stoi(oper.top());
                    oper.pop();
                }
                oper.pop();
                a*=2;
                string arr = to_string(a);
                oper.push(arr);
            }
        }

    }
    while(!oper.empty()){
        b+=stoi(oper.top());
        oper.pop();
    }
    return b;  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s="((((((())))()())))"; //80
    cout<<scoreOfParentheses(s);

    return 0;
}