#include <bits/stdc++.h>
using namespace std;

int priority(char op)    
{  
if(op == '+' || op == '-') return 1;  
if (op == '*' || op == '/') return 2;  
if(op == '^') return 3;       
return 0;
}

bool comparate (char op1, char op2)  
{  
int p1 = priority(op1);  
int p2 = priority(op2);  

if (p1 == p2){  
    if (op1 == '^' ) return false;  
    return true;  
}  
return  (p1>p2 ? true : false);  
} 

string toSufix(string& infix){  
    stack <char> a;  
    string pos ="";      
  
    a.push( '(' );  
    infix += ')';  
  
    for(int i = 0; i<infix.length(); i++){      
        if(infix[i] == '(')  
            a.push(infix[i]);  
        else if((infix[i]>='a' && infix[i]<='z') ||(infix[i]>='A' && infix[i]<='Z')||(infix[i]>='0' && infix[i]<='9'))  
            pos += infix[i];  
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^'){  
            while(!a.empty() && comparate(a.top(), infix[i])){  
                pos += a.top();  
                a.pop();  
            }  
            a.push(infix[i]);  
        }  
        else if(infix[i] == ')'){  
            while(!a.empty() && a.top() != '('){  
                pos += a.top();  
                a.pop();  
            }  
            a.pop();  
        }  
    }  
    return pos;  
}  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string pos;
    string infix;
    cin>>n;
    for(int i=0;i<=n;i++){
        getline(cin,infix);
        pos=toSufix(infix);
        cout<<pos<<"\n";
    }
    return 0;
}