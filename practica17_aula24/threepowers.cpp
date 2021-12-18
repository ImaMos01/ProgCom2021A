#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flg= true;
    long long int n=0;
    while(cin>>n){
        if(n==0)break;
        long long int three_pow=0;
        cout<<"{";
        flg=false;
        n--;
        while(n>0){
            if( (n&1) == 1){
                if(flg) cout<<",";
                flg=true;
                long long int ans=pow(3,three_pow);
                cout<<" "<<ans;
            }
            n>>=1;
            three_pow++;
        }
        cout<<" }\n";
    }
    return 0;
}