#include <bits/stdc++.h>
 
using namespace std;
 
void dfs(vector<int>& visit,vector<vector<int>> plan,stack<int>& conn,int p){
    visit[p]=1;
    for(auto&i: plan[p]){
        if(visit[i]==0){
            dfs(visit,plan,conn,i);
        }
    }
    conn.push(p);
}
 
void dfs_r(vector<int>& visit,vector<int>& sum,vector<vector<int>> plan,int p,int& group){
    visit[p]=1;
    sum[p]=group;
    for(auto&i: plan[p]){
        if(visit[i]==0){
            dfs_r(visit,sum,plan,i,group);
        }
    }
}
 
void kingdoms(vector<vector<int>>& fplan,vector<vector<int>>& splan,int n, int m){
    vector<int> visitA(n+1,0),visitB(n+1,0), sum(n+1,0);
    stack<int> conn;
    int grups=0;
    for(int i=1;i<=n;i++){
        if(visitA[i]==0){
            dfs(visitA,fplan,conn,i);
        }
    }
    while(!conn.empty()){
        if(visitB[conn.top()]==0){ 
            grups++;
            dfs_r(visitB,sum,splan,conn.top(),grups);
        }
        conn.pop();
    }
 
    cout<<grups<<"\n";
    for(int i=1;i<=n;i++){
        cout<<sum[i]<<" ";
    }
}
 
 
int main(){
    int n=0,m=0,x=0,y=0;
    cin>>n>>m;
 
    vector<vector<int>> fplan(n+1,vector<int>(1,0));
    vector<vector<int>> splan(n+1,vector<int>(1,0));
 
    for(int i=0;i<m;i++){
        cin>>x>>y;
        fplan[x].push_back(y);
        splan[y].push_back(x);
    }
 
    kingdoms(fplan,splan,n,m);
    return 0;
}