#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    if(n<3){
        return n;
    }
    
    vector<int> op(n+1,0);
    op[0]=1;
    op[1]=1;
    for(int i=2; i<=n;i++){
        op[i]=op[i-1]+op[i-2];
    }

    return op[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<climbStairs(2)<<"\n";
    cout<<climbStairs(3)<<"\n";
    cout<<climbStairs(4)<<"\n";
    cout<<climbStairs(5)<<"\n";

    return 0;
}