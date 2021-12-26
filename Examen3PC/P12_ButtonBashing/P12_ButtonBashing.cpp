#include <bits/stdc++.h>
using namespace std;

void microw(queue<pair<int,int>> col,vector<int> vald,map<int,int> ds,int tm){
    int n=vald.size(),op=0;
    while(!col.empty()){
        pair<int,int> f=col.front();
        col.pop();
        for(int i=0;i<n;i++){
            op=f.first + vald[i];
            if(op<0){
                op=0;
            }
            if(op>3600){
                op=3600;
            }
            auto ps = ds.find(op);
            if((ps==ds.end())||(f.second+1<ds[op])){
                ds[op]=f.second+1;
                col.push({op,f.second+1});
            }

        }
    }
    auto ps=ds.find(tm);
    if(ps==ds.end()){
        op=tm;
        while(ps==ds.end()){
            op++;
            ps=ds.find(op);
        }
        cout<<ds[op]<<" "<<op-tm<<"\n";
    }
    else{
        cout<<ds[tm]<<" 0\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cs=0,temp=0;
    cin>>cs;
    for(int i=0; i<cs;i++){
        int bt=0,tm=0;
        cin>>bt>>tm;
        map<int,int> ds;
        vector<int> vald;

        for(int j=0;j<bt;j++){
            cin>>temp;
            vald.push_back(temp);
        }
        queue<pair<int,int>> col;
        ds[0]=0;
        col.push({0,0});
        microw(col,vald,ds,tm);
    }
    return 0;
}
