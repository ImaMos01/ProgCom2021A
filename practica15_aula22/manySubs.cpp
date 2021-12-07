#include <bits/stdc++.h>
using namespace std;

int uniqueSub(string arr){
    if(arr.empty()) return 0;
    int n=arr.length();
    map<string,int> sor;
    vector<int> lcp(n,0);
    string sub="";
    int sumtot=(n*(n+1))/2;
    for(int i=n-1;i>=0;i--){
        sub=arr[i]+sub;
        sor[sub]=i;
    }

    int k=0,cont=0;
    lcp[0]=0;
    string prev;
    for(auto j: sor){
        if(k>=1){
            cont=0;
            string temp=j.first;
            for(int i=0;i<temp.length();i++){
                if(i>=prev.length()){
                    lcp[k]=lcp[k-1]+cont;
                    break;
                }
                if(prev[i]==temp[i]){ 
                    cont++;
                }
                else{
                    lcp[k]=lcp[k-1]+cont;
                    break;
                }

            }
        }
        prev=j.first;
        k++;
    }
    
    return sumtot-lcp[n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cont=0,aux=0;
    string arr;
    while(cin>>arr){
        string temp="";
        int n=arr.length();
        for(int i=0; i<n;i++){
            if(arr[i]=='?'){
                cout<<uniqueSub(temp)<<"\n";
            }
            else{
                temp+=arr[i];
            }
        }
    }
    return 0;
}
