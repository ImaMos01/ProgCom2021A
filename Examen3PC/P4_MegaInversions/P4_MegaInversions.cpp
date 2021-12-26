#include <bits/stdc++.h>

using namespace std;

int limi = 100005;
vector<long long int> a(limi,0),b(limi,0);

void qry(vector<long long int>& arr,long long int x,long long int n,long long int& rep){
    while(x<=n){
        rep+=arr[x];
        x+=x&-x;
    }
}

void act(vector<long long int>& arr,long long int x,long long temp){
    while(x>0){
        arr[x]+=temp;
        x-=x&-x;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n=0,x=0,ans=0;
    cin>>n;
    for(long long int i=0; i<n;i++){
        cin>>x;
        act(a,x,1);
        long long int rep=0;
        qry(a,x+1,n,rep);
        act(b,x,rep);
        qry(b,x+1,n,ans);
    }
    cout<<ans;

    return 0;
}