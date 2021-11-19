#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    for(int i=1; i<n;i++){
        grid[0][i]+=grid[0][i-1];
    }
    for(int j=1; j<m;j++){
        grid[j][0]+=grid[j-1][0];
    }
    for(int i=1; i<m;i++){
        for(int j=1;j<n;j++){
            grid[i][j]=grid[i][j]+min(grid[i-1][j],grid[i][j-1]);
        }
    }
    return grid[m-1][n-1];                
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> grid={{1,2,1},{1,5,1},{4,2,1}};
    cout<<minPathSum(grid);
    return 0;
}