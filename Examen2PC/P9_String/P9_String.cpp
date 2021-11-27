
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0;
    while(cin>>n){
        vector<long long> strin(n*10,0);
        for(int i=0; i<n*10;i++){
            cin>>strin[i];
        }

        long long s=n*20, localmax=0,globalmax=INT_MIN,j=0,k=0,posx=0;
        bool again=false;
        
        while(j<s){
            if(k==(n*10)){ k=0;again=true;}
            localmax=localmax+strin[k];
    
            if(posx==k && again==true)break;
            else{
                if(globalmax<localmax) globalmax=localmax;
            }

            if(localmax<=0){ 
                if(k==(n*10)-1)posx=0;
                else posx=k+1; 
                localmax=0;
            }
            j++;k++;
        }
        cout<<globalmax<<"\n";
    }

    return 0;
}
