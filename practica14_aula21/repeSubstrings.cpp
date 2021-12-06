#include <bits/stdc++.h>
using namespace std;

int repeatString(string arr){
    int n=arr.length(),ans=0;
    priority_queue<string,vector<string>,greater<string>> sor;
    vector<int> lcp(n,0);
    for(int i=0;i<n;i++){
        sor.push(arr.substr(i));
    }

    int k=0,cont=0;
    string sub="";
    while(!sor.empty()){
        if(k>=1){
            cont=0;
            int lp=sor.top().length(),mp=sub.length();
            for(int i=0;i<lp;i++){
                if(i>=mp){
                    lcp[k-1]=cont;
                    break;
                }
                if(sub[i]==sor.top()[i]){ 
                    cont++;
                }
                else{
                    lcp[k-1]=cont;
                    break;
                }

            }
        }
        sub=sor.top();
        sor.pop();
        k++;
    }

    lcp[n-1]=0;
    ans=lcp[0];
    int uy=lcp.size();
    for(int i=1; i<uy;i++){
        if(lcp[i]>lcp[i-1]) {
            ans+=(lcp[i]-lcp[i-1]);
        }
    }
    
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x=0;
    string arr;
    cin>>x;
    cin.ignore();
    for(int i=0;i<x;i++){
        getline(cin, arr);
        cout<<repeatString(arr)<<"\n";   
    }
    return 0;
}