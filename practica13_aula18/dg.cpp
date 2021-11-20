#include <bits/stdc++.h>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    if(dungeon.empty() || dungeon.size()==0 || dungeon[0].size()==0){
        return 0;
    }
    
    int m=dungeon.size();
    int n=dungeon[0].size();

    vector<vector<int>> minpath(m,vector<int>(n,0));
    for(int i=m-1; i>=0;i--){
        for(int j=n-1; j>=0;j--){
            if(i==m-1 && j==n-1){
                minpath[m-1][n-1]=max(1,1-dungeon[m-1][n-1]);
            }
            else if(i==m-1){
                minpath[m-1][j]=max(minpath[m-1][j+1]-dungeon[m-1][j],1);
            }
            else if(j==n-1){
                minpath[i][n-1]=max(minpath[i+1][n-1]-dungeon[i][n-1],1);
            }
            else{
                int a = max(minpath[i+1][j]-dungeon[i][j],1);
                int b = max(minpath[i][j+1]-dungeon[i][j],1);
                minpath[i][j]=min(a,b);
            }
        }
    }
    return minpath[0][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> rooms={{1,3},{3,0,1},{2},{0}};

    cout<<calculateMinimumHP(rooms);
}