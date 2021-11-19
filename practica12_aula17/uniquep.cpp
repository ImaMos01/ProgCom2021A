#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    vector<vector<int>> rut(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
       if(obstacleGrid[i][0]!=1){
           rut[i][0]=1;
       }
       else{
           break;
       }
    }

    for(int j=0;j<n;j++){
        if(obstacleGrid[0][j]!=1){
           rut[0][j]=1;
       }
       else{
           break;
       }
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(obstacleGrid[i][j]!=1){
                rut[i][j]+=rut[i-1][j]+rut[i][j-1];
            }
        }
    }
    return rut[m-1][n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}