#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0,g=0, cas=1;
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>g;
        map<long long int,int> arr;
        long long int op=0;
        for(int j=0; j<g;j++){
            cin>>op;
            arr[op]++;
        }
        for (std::map<long long int,int>::iterator it=arr.begin(); it!=arr.end(); ++it){
            if(it->second<=1){
                op = it->first;
                break;
            }
        }
        cout<<"Case #"<<cas<<": "<<op<<"\n";
        cas++;
    }
    return 0;
}