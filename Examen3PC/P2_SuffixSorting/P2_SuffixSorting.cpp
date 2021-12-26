#include <bits/stdc++.h>
using namespace std;


const long long int limi=1e5+5;
long long int n=0,t=0,ans=0;
string arr;
long long int sa[limi];
long long int tmp[limi],pos[limi];

bool compare(long long int i,long long int j){
    if(pos[i]!=pos[j]) return (pos[i]<pos[j]);
    i+=t;
    j+=t;
    if(i<n && j<n) return (pos[i]<pos[j]);
    return (i>j);
}

void suffixArray(){
    for(long long int i=0; i<n;i++){
        sa[i]=i;
        pos[i]=arr[i];
    }
    for(t=1;t<2*n+1;t*=2){
        sort(sa,sa+n,compare);
        for(long long int i=0; i<n-1;i++){
            tmp[i+1]=tmp[i];
            if(compare(sa[i],sa[i+1])) tmp[i+1]++;
        }
        for(long long int i=0; i<n;i++){
            pos[sa[i]]=tmp[i];
        }
        if(tmp[n-1]==n-1) break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int x=0,y=0;
    while(getline(cin,arr)){
        n=arr.size();
        suffixArray();

        cin>>x;
        for(int i=0;i<x;i++){
            cin>>y;
            if(i>0){
                cout<<" ";
            }
            cout<<sa[y];
        }
        cout<<"\n";
        
        cin.ignore();
    }
    return 0;
}
