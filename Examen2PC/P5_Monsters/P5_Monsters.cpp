
#include <bits/stdc++.h>
using namespace std;


void bfs(vector<vector<char>>& dun, int i, int j){
    vector<vector<int>> yx ={{1,-1,0,0},{0,0,1,-1}};
    vector<char> dir ={{'D','U','R','L'}};
    
    vector<vector<int>> cost(dun.size(),vector<int>(dun[0].size(),0));
    vector<vector<string>> path(dun.size(),vector<string>(dun[0].size()));
    
    queue<vector<int>> visit;

    visit.push({i,j});
    while(!visit.empty()){
        vector<int> op = visit.front();
        visit.pop();
        int r=op[0],c=op[1];

        for(int k=0;k<4;k++){
            int xi=r+yx[0][k];
            int yi=c+yx[1][k];

            if(0<=xi && xi<dun.size() && 0<=yi && yi<dun[0].size() && dun[xi][yi]!='#' && dun[xi][yi]!='M' && cost[xi][yi]==0){
                visit.push({xi,yi});
                cost[xi][yi]=cost[r][c]+1;
                path[xi][yi]=path[r][c]+dir[k];
            }
            if(dun[xi][yi]!='#' && dun[xi][yi]!='M' && dun[xi][yi]!='A'){
                if(xi<=0 || xi>=dun.size()-1 ||yi<=0 ||yi>=dun[0].size()-1){
                    cout<<"YES\n"<<cost[xi][yi]<<"\n"<<path[xi][yi]<<"\n";
                    return;
                }
            }
        }
    }
    cout<<"NO\n";

}


void bfs(){
    vector<pair<int,int>> monster;
    vector<vector<int>> p;
    map<pair<int,int>,pair<int,int>> dung;
    pair<int,int> po,pe;
    vector<vector<int>> yx ={{-1,1,0,0},{0,0,1,-1}};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0,m=0,x=0,y=0,d=0;
    cin>>n>>m;
    vector<vector<char>> dungeon(n,vector<char>(m,'.'));

    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>dungeon[i][j];
            if(dungeon[i][j]=='A'){
                x=i;
                y=j;
            }
        }
    }
    if(x==0||x==n-1||y==0||y==m-1){
        cout<<"YES\n"<<0;
        return 0;
    }

    bfs(dungeon, x, y);
    return 0;
}
