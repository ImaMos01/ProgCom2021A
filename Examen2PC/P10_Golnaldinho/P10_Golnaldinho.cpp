
#include <bits/stdc++.h>
using namespace std;

vector<int> arr(500001,0);

int rem(int x){
    int sum=0;
    while(x>0){
        sum+=arr[x];
        x-=(x & (-x));
    }
    return sum;
}

void act(int& x, int y){
    while(x<500001){
        arr[x]+=y;
        x+=(x&(-x));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=0,x=0;
    cin>>n;

    for(int i=1; i<=n;i++){
        cin>>x;
        int op=x-rem(x);
        cout<<op;
        if(n==i) cout<<"\n";
        else cout<<" ";
        act(x,1);
    }

    return 0;
}