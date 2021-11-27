#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int>& coor,vector<vector<vector<char>>>& dun,vector<vector<vector<int>>>& path){
    vector<vector<int>> xyz ={{1,-1,0,0,0,0},{0,0,1,-1,0,0},{0,0,0,0,1,-1}};
    queue<vector<int>> visit;
    visit.push(coor);

    while(!visit.empty()){
        vector<int> curr = visit.front();
        visit.pop();
        if(dun[curr[0]][curr[1]][curr[2]]=='E'){
            cout << "Escaped in " << path[curr[0]][curr[1]][curr[2]] << " minute(s).\n";
            return;
        }
        for(int i=0; i<6;i++){
            vector<int> temp(3,0);
            temp[0]=curr[0]+xyz[0][i];
            temp[1]=curr[1]+xyz[1][i];
            temp[2]=curr[2]+xyz[2][i];
            if(temp[0]>=0 && temp[0]<dun.size() && temp[1]>=0 && temp[1]<dun[0].size() && temp[2]>=0 && temp[2]<dun[0][0].size() && dun[temp[0]][temp[1]][temp[2]]!='#' && path[temp[0]][temp[1]][temp[2]]==0){
                visit.push(temp);
                path[temp[0]][temp[1]][temp[2]]=path[curr[0]][curr[1]][curr[2]]+1;
            }
        }
    }
    cout<<"Trapped!\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int L=0,R=0,C=0;
    vector<int> coord(3,0);
    char opc;
    while(cin>>L>>R>>C){
        if(L==0 && R==0 && C==0) break;
        vector<vector<vector<char>>> dungeon(L,vector<vector<char>>(R,vector<char>(C,'.')));
        vector<vector<vector<int>>> path(L,vector<vector<int>>(R,vector<int>(C,0)));
        
        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
                for(int k=0;k<C;k++){
                    cin>>dungeon[i][j][k];
                    if(dungeon[i][j][k]=='S'){
                        coord[0]=i;
                        coord[1]=j;
                        coord[2]=k;
                    }
                }
            }
        }

        bfs(coord,dungeon,path);
    }
    return 0;
}