#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s){
    stack<string> oper;
    int cont=0;
    for(int i=0; i<s.length();i++){
        if(s[i]=='('){
            oper.push("(");
            cont++;
        }
        else if(s[i]==')'){
            if(oper.empty()==true){
                cont++;
            }
            else{
                oper.pop();
                cont--;
            }
        }

    }
    return cont;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s="(((";


    return 0;
}