#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<char> name; 
    long long int opc=0, n=0,m=0;
    char x,d;
    long long int a=0,b=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        name.push_back(x);
    }

    for(int i=0; i<m; i++){
        cin>>opc;
        if(opc==1){
            cin>>a>>d;
            name[a-1]=d;
        }
        else{
            cin>>a>>b;
            int p=a-1,q=b-1;
            int mid=(p+q)/2,f=1;

            while(p<=mid){
                if(name[p]!=name[q]){
                    f=0;
                break;
                }
                p++;
                q--;
            }
            if(f==1){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }   
        }
    }
    return 0;
}
