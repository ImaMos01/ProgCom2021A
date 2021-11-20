#include <bits/stdc++.h>
using namespace std;

void dfs (vector<vector<int>> image,int sr,int sc,map<pair<int,int>,int>& vis,int oldColor){
    if(vis[{sr,sc}]==1 || sr<0 || sr>=image.size() || sc<0 || sc>=image[sr].size()||image[sr][sc] < oldColor){
        return;
    }

    vis[{sr,sc}]=1;
    dfs(image, sr+1, sc,vis, image[sr][sc]);
    dfs(image, sr-1, sc,vis, image[sr][sc]);
    dfs(image, sr, sc+1,vis, image[sr][sc]);
    dfs(image, sr, sc-1,vis, image[sr][sc]);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m=heights.size();
    int n=heights[0].size();
    map<pair<int,int>,int> pacif;
    map<pair<int,int>,int> atlan;

    for(int i=0; i<m;i++){
        dfs(heights,i,0,pacif,heights[i][0]);
        dfs(heights,i,n-1,atlan,heights[i][n-1]);
    }

    for(int i=0; i<n;i++){
        dfs(heights,0,i,pacif,heights[0][i]);
        dfs(heights,m-1,i,atlan,heights[m-1][i]);
    }

    vector<vector<int>> out;
    for(int i=0; i<m;i++){
        for(int j=0;j<n;j++){
            if(pacif[{i,j}]==1 && atlan[{i,j}]==1){
                out.push_back({i,j});
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}