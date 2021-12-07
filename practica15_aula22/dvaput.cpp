#include <bits/stdc++.h>
using namespace std;

int x=0;
string sub="";

map<string,int> sor;

int lps(){
    int n=sub.length(),maxcom=0;
    for(int i=0;i<n;i++){
        sor[sub.substr(i)]=0;
    }

    sub="";
    int k=0,cont=0;
    for(std::map<string,int>::iterator j=sor.begin(); j!=sor.end(); ++j){
        if(k>=1){
            cont=0;
            for(long long int i=0;i<j->first.length();i++){
                if(i>=sub.length()){
                    j->second=cont;
                    break;
                }
                if(sub[i]==j->first[i]){ 
                    cont++;
                }
                else{
                    j->second=cont;
                    break;
                }

            }
            maxcom=max(j->second,maxcom);
        }
        sub=j->first;
        k++;
    }
    
    return maxcom;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>x;
    char d;
    for(int i=0; i<x;i++){
        cin>>d;
        sub+=d;
    }

    cout<<lps()<<"\n";

    return 0;
}