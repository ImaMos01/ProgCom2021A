//longest common subsequence
#include <bits/stdc++.h>
using namespace std;

int lcs(string p0,string p1,int m,int n){
    int result=0;
    if(m==0 || n==0){
        result = 0;
    }
    else if(p0[m-1]==p1[n-1]){
        result = 1+lcs(p0,p1,m-1,n-1);
    }
    else{
        int temp0 = lcs(p0,p1,m-1,n);
        int temp1 = lcs(p0,p1,m,n-1);
        result = max(temp0,temp1);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string p0="abcdefghij";
    string p1="ecdgi";
    cout<<"string 1: "<<p0<<"\n";
    cout<<"string 2: "<<p1<<"\n";
    cout<<lcs(p0,p1,p0.size(),p1.size())<<"\n";
    p0="abcdefghij";
    p1="ecdgi";
    cout<<"string 1: "<<p0<<"\n";
    cout<<"string 2: "<<p1<<"\n";
    cout<<lcs(p0,p1,p0.size(),p1.size())<<"\n";
    
    return 0;
}