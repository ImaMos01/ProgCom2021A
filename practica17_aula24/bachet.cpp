#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n=0,m=0,x=0;
    while(cin>>n){
        cin>>m;
        vector<int> arr(m,0);
        vector<bool> op(n+1);
        
        for(int i=0; i<m; i++){
            cin>>arr[i];
        }

        for(int i=1; i<=n;i++){
            for(auto& j : arr){
                if(i-j >=0 && !op[i-j]){
                    op[i]=true;
                    break;
                }
            }
        }
        if(op[n]==true){
            cout<<"Stan wins\n";
        }
        else{
            cout<<"Ollie wins\n";
        }
    }
    return 0;
}