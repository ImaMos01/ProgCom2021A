#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<vector<int>> sum(n,vector<int>(n,0));
    for(int i=0; i<n;i++){
        sum[0][i]=grid[0][i];
    }

    for(int i=1; i<n;i++){
        vector<pair<int,int>> ord;
        for(int j=0; j<n;j++){
            ord.push_back({sum[0][i-1],j});
        }
        sort(ord.begin(),ord.end());
        
        for(int j=0; j<n;j++){
            if(j!=ord[0].second){
                sum[i][j]=ord[0].first+grid[i][j];
            }
            else{
                sum[i][j]=ord[1].first+grid[i][j];
            }
        }
    }

    int ans=INT_MAX;
    for(int i=0; i<n;i++){
        ans=min(ans,sum[n-1][i]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}