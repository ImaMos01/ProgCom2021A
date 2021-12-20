#include <bits/stdc++.h>
using namespace std;

string text,pattern;
int lps[100001];
int n=0,m=0;


void findlps(){
    int i=1,j=0;
    while(i<m){
        if(pattern[i] == pattern[j]){
            j++;
            lps[i]=j;
            i++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }

}

void KMP(){
    findlps();
    int i=0,j=0;
    while(i<n){
        if(pattern[j] == text[i]){
            i++;
            j++;
        }
        if(j==m){
            cout<<i-j<<" ";
            j=lps[j-1];
        }
        else if((i<n) && (pattern[j]!=text[i])){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i+=1;
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(getline(cin,pattern)){
        getline(cin,text);
        m=pattern.length();
        n=text.length();
        KMP();
        cout<<"\n";
    }
    return 0;
}

