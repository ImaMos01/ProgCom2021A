#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& grid,int i,int j){
    if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size()||grid[i][j]==0)
        return 0;
    grid[i][j]=0;
    int cont=1;
    cont+=dfs(grid,i+1,j);
    cont+=dfs(grid,i-1,j);
    cont+=dfs(grid,i,j+1);
    cont+=dfs(grid,i,j-1);
    return cont;
}

int maxAreaOfIsland(vector<vector<int>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1)
                ans=max(ans,dfs(grid,i,j));
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> island={{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    cout<<maxAreaOfIsland(island); 
    return 0;
}