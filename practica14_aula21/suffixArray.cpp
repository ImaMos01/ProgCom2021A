#include <bits/stdc++.h>
using namespace std;

vector<int> suffix(string arr){
    int n=arr.length(),ans=0;
    map<string,int> sor;
    vector<int> suff(n,0);
    for(int i=0;i<n;i++){
        sor[arr.substr(i)]=i;
    }

    int k=0,cont=0;
    for(auto j: sor){
        suff[k]=j.second;
        k++;
    }
    
    return suff;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string arr="camel";
    
    cout<<"INPUT: camel \nOutput: ";
    vector<int> op= suffix(arr);
    for(auto&i : op){
        cout<<i<<" ";
    }

    return 0;
}