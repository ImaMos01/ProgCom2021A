#include <bits/stdc++.h>
using namespace std;


const long long int limi=1e5+5;
long long int n=0,t=0,ans=0;
string arr;
long long int sa[limi];
deque<int> lcp;
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

void find_lcp(){
    long long int p=0;
    lcp.assign(n,0);
    for(long long int i=0; i<n;i++){
        if(pos[i]!=n-1){
            long long int j=sa[pos[i]+1];
            while(arr[i+p]==arr[j+p])p++;
            lcp[pos[i]]=p;
            if(p>0) p--;
        }
    }
    int tp=lcp[n-1];
    lcp.push_front(tp);
    lcp.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(getline(cin,arr)){
        if(arr=="") break;
        arr.erase(remove_if(arr.begin(),arr.end(),::isspace),arr.end());
        
        n=arr.size();

        suffixArray();
        find_lcp();
    
        for(int i=1;i<=n;i++){
            t=0;
            ans=0;
            for(int j=0;j<n;j++){
                if(lcp[j]>=i){
                    t++;
                    ans=max(ans,t);
                }
                else{
                    t=0;
                }
            }
            if(ans>=1){
                cout<<ans+1<<"\n";
            }
            else{
                break;
            }
        }
        cout<<"\n";
    }
    return 0;
}
