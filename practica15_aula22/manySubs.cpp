#include <bits/stdc++.h>
using namespace std;

const long long int limi=2e5+5;
int n=0,t=0,ans=0;
string arr;
int sa[limi],lcp[limi];
int tmp[limi],pos[limi];

bool compare(int i, int j){
    if(pos[i]!=pos[j]) return (pos[i]<pos[j]);
    i+=t;
    j+=t;
    if(i<n && j<n) return (pos[i]<pos[j]);
    return (i>j);
}

void suffixArray(){
    for(int i=0; i<n;i++){
        sa[i]=i;
        pos[i]=arr[i];
    }
    for(t=1;t<2*n+1;t*=2){
        sort(sa,sa+n,compare);
        for(int i=0; i<n-1;i++){
            tmp[i+1]=tmp[i];
            if(compare(sa[i],sa[i+1])) tmp[i+1]++;
        }
        for(int i=0; i<n;i++){
            pos[sa[i]]=tmp[i];
        }
        if(tmp[n-1]==n-1) break;
    }
}

void find_lcp(){
    int p=0;
    int sumtot=(n*(n+1))/2;
    for(int i=0; i<n;i++){
        if(pos[i]!=n-1){
            int j=sa[pos[i]+1];
            while(arr[i+p]==arr[j+p])p++;
            lcp[pos[i]]=p;
            ans+=p;
            if(p>0) p--;
        }
    }
    cout<<sumtot-ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x=0;
    string temp;
    while(cin>>temp){
        if(temp=="0") break;
        int k=temp.length();
        for(int i=0; i<k;i++){
            if(temp[i]=='?'){
                suffixArray();
                find_lcp();
            }
            else{
                arr+=temp[i];
                n++;
            }
        }
        n=0;
        arr.clear();
    }
    return 0;
}
