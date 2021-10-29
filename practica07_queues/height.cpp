#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nc=0,h=0;
    long long n;
    cin>>nc;
    for(int i=0;i<nc;i++){
        cin>>n;
        map<int,int> arr;
        for(long long j=0;j<n;j++){
            cin>>h;
            if(arr[h]!=0){
                arr[h]++;
            }
            else{
                arr[h]=1;    
            }
        }
        for (map<int,int>::iterator it=arr.begin(); it!=arr.end(); ++it){
            int op=it->second;
            while(op>0){
                cout<<it->first<<" ";
                op--;
            }
        }
        cout<<"\n";
    }

    return 0;
}