#include <bits/stdc++.h>
using namespace std;

void palindrome(vector<char>& name,long long int m){
    long long int opc=0,x=0;
    char y;
    for(long long int i=0; i<m; i++){
        cin>>opc>>x>>y;
        if(opc==1){
            name[x-1]=y;
        }
        else{
            int n=y-'0',f=1,mid=((n+x-1)/2),j=x-1;
            while(j<=mid){
                if(name[j]!=name[n-j+x-2]){
                    f=0;
                    break;
                }
                j++;
            }
            if(f==1){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<char> name; 
    long long int n=0,m=0;
    char x;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        name.push_back(x);
    }
    palindrome(name,m);
    return 0;
}