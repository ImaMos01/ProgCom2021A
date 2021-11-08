#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid,int i,int j){
    if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size()||grid[i][j]=='W')
        return;
    
    grid[i][j]='W';
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);
}

int minAreaOfIsland(vector<vector<char>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='L'){
                dfs(grid,i,j);
                ans++;  
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r=0,c=0;
    char charac;
    cin>>r>>c;
    vector<vector<char>> island;
    for(int i=0; i<r;i++){
        vector<char> op;
        for(int j=0;j<c;j++){
            cin>>charac;
            op.push_back(charac);
        }
        island.push_back(op);
    }
    cout<<minAreaOfIsland(island);
    return 0;
}