#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string kids;
    long long int ans=0;
    vector<long long int> dig(3,0);
    int s=0;
    cin>>kids;
    for(int i=0; i<kids.length();i++){
        long long int op=kids[i]-'0';
        for(int j=op+1;j<3;j++){
            ans+=dig[j];
        }
        dig[op]++;
    }
    cout<<ans<<"\n";
    return 0;
}